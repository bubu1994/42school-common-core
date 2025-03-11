/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:08:00 by sbaumann          #+#    #+#             */
/*   Updated: 2025/03/11 09:28:51 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
*	The presence a map was checked beforehand
*	Returns -1 if there is an error in the map
*/
int	find_map(t_mlx *cub, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ret_error(NULL, "Opening file"));
	while (1)
	{
		line = get_next_line(fd);
		if (valid_map_line(cub, line))
		{
			if (build_map(cub, &line, fd) == -1)
			{
				free(line);
				close(fd);
				return (-1);
			}
			free(line);
			break ;
		}
		free(line);
	}
	close(fd);
	return (1);
}

/*
*	Returns -1 if a player is not found
*	Returns -1 if the map is not closed
*/
int	check_map(t_mlx *cub)
{
	int		x;
	int		y;
	char	**map_copy;

	map_copy = copy_arr(cub->scene.map);
	if (cub->cam.x == 0 || cub->cam.y == 0)
		return (ret_error(NULL, NO_PLAYER));
	y = 0;
	while (cub->scene.map[y])
	{
		x = 0;
		while (cub->scene.map[y][x])
		{
			if ((cub->scene.map[y][x] == '0' || cub->scene.map[y][x] == '2')
				&& flood_fill(cub, &map_copy, y, x) == 0)
			{
				array_free(map_copy);
				return (ret_error(NULL, "Unclosed map"));
			}
			x++;
		}
		y++;
	}
	array_free(map_copy);
	return (1);
}

void	flush_space_lines(int fd, char **line)
{
	while (*line && line_is_spaces(*line))
	{
		free(*line);
		*line = get_next_line(fd);
	}
}

/*
*	Stores the height and max width of the map
*	If there is something after the map, returns -1 (the map is not parsed yet)
*/
int	read_map(t_mlx *cub, int fd, char **line)
{
	int	w;
	int	max_w;
	int	h;

	h = 0;
	max_w = 0;
	while (*line && valid_map_line(cub, *line))
	{
		h++;
		w = ft_strlen(*line);
		if (w > max_w)
			max_w = w;
		free(*line);
		*line = get_next_line(fd);
	}
	cub->scene.h_map = h;
	cub->scene.w_map = max_w;
	flush_space_lines(fd, line);
	if (h > MAX_MAP_SIZE || max_w > MAX_MAP_SIZE)
		return (ret_error(NULL, MAP_SIZE_ERR));
	if (*line == NULL)
		return (1);
	return (ret_error(*line, INV_CHAR));
}

/*
*	Find the player spawn position
*/
int	build_map(t_mlx *cub, char **line, int fd)
{
	int		i;

	i = 0;
	cub->scene.map = malloc(sizeof(char *) * (cub->scene.h_map + 1));
	if (!cub->scene.map)
		return (ret_error(NULL, MALLOC_FAIL));
	while (*line && valid_map_line(cub, *line))
	{
		if (find_player(cub, line, i) == -1)
		{
			cub->scene.map[i] = NULL;
			return (-1);
		}
		cub->scene.map[i++] = ft_strdup(*line);
		free(*line);
		*line = get_next_line(fd);
	}
	cub->scene.map[i] = NULL;
	return (check_map(cub));
}
