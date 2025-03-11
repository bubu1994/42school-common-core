/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:45:35 by gebuqaj           #+#    #+#             */
/*   Updated: 2025/03/11 09:28:26 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
*	Returns -1 if there is already a spawn position stored
*	Stores the position and angle of the player and set the value's
*	position to '0'
*/
int	find_player(t_mlx *cub, char **line_map, int y)
{
	int		i;

	i = 0;
	while ((*line_map)[i])
	{
		if ((*line_map)[i] == 'N' || (*line_map)[i] == 'W'
			|| (*line_map)[i] == 'S' || (*line_map)[i] == 'E')
		{
			if (cub->cam.x || cub->cam.y)
				return (ret_error(NULL, "Two spawn positions"));
			if ((*line_map)[i] == 'N')
				cub->cam.angle = M_PI / 2;
			else if ((*line_map)[i] == 'W')
				cub->cam.angle = M_PI;
			else if ((*line_map)[i] == 'S')
				cub->cam.angle = 3 * M_PI / 2;
			else if ((*line_map)[i] == 'E')
				cub->cam.angle = 2 * M_PI;
			cub->cam.x = i + 0.5;
			cub->cam.y = y + 0.5;
			(*line_map)[i] = '0';
		}
		i++;
	}
	return (1);
}

/*
*	Flood all walkable cells recursively
*	Returns 1 if the cell is '1' or 'V'
*	Returns 0 if the cell is out of bounds or a space
*	set the cell to 'V'
*	Checks cells in the four directions
*	Returns 1 if all directions are valid
*/
int	flood_fill(t_mlx *cub, char ***map_copy, int y, int x)
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	w_line;

	if (y >= cub->scene.h_map || y < 0)
		return (0);
	w_line = ft_strlen((*map_copy)[y]);
	if (y < 0 || x < 0 || x >= w_line)
		return (0);
	if ((*map_copy)[y][x] == '1' || (*map_copy)[y][x] == 'V')
		return (1);
	if ((*map_copy)[y][x] == ' ')
		return (0);
	(*map_copy)[y][x] = 'V';
	up = flood_fill(cub, map_copy, y - 1, x);
	down = flood_fill(cub, map_copy, y + 1, x);
	left = flood_fill(cub, map_copy, y, x - 1);
	right = flood_fill(cub, map_copy, y, x + 1);
	return (up && down && left && right);
}

int	open_files(char *file, int *fd)
{
	int	dir_fd;

	dir_fd = open(file, __O_DIRECTORY);
	if (dir_fd != -1)
	{
		close(dir_fd);
		return (ret_error(file, "Argument is a directory"));
	}
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		return (ret_error(NULL, "Opening file"));
	return (1);
}

static int	parse_file_lines(t_mlx *cub, int fd)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	while (line != NULL)
	{
		split = ft_split(line, ' ');
		if (parse_line(cub, split, &line, fd) == -1)
		{
			array_free(split);
			free(line);
			while (1)
			{
				line = get_next_line(fd);
				if (line == NULL)
					break ;
				free(line);
			}
			return (-1);
		}
		array_free(split);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

/*
*	Main parser. returns -1 for an error check if file is a directory
*	Opens file, parse every line to find NO, SO, WE, EA, F, C,
*	width and height of map (the map is not yet created)
*/
int	parsing(t_mlx *cub, char *file)
{
	int	fd;

	if (open_files(file, &fd) == -1)
		return (-1);
	if (parse_file_lines(cub, fd) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if (check_data(cub) == -1)
		return (-1);
	cub->scene.m_scale = opti_scaling_minimap(&cub->scene);
	if (find_map(cub, file) == -1)
		return (-1);
	cub->cam.cos = cos(cub->cam.angle);
	cub->cam.sin = sin(cub->cam.angle);
	return (1);
}
