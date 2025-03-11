/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaumann <sbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:41:22 by gebuqaj           #+#    #+#             */
/*   Updated: 2025/03/05 18:29:09 by sbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
*	Returns -1 if a texture, color or map is not found
*/
int	check_data(t_mlx *cub)
{
	if (!cub->textures.no)
		return (ret_error("NO", TEXTURE_NOT_FOUND));
	if (!cub->textures.so)
		return (ret_error("SO", TEXTURE_NOT_FOUND));
	if (!cub->textures.we)
		return (ret_error("WE", TEXTURE_NOT_FOUND));
	if (!cub->textures.ea)
		return (ret_error("EA", TEXTURE_NOT_FOUND));
	if (!cub->scene.floor_c)
		return (ret_error("F", COLOUR_NOT_FOUND));
	if (!cub->scene.ceiling_c)
		return (ret_error("C", COLOUR_NOT_FOUND));
	if (cub->scene.h_map == 0)
		return (ret_error(NULL, MAP_NOT_FOUND));
	return (1);
}

/*
*	If the line contains other than space, returns -1
*/
int	line_is_spaces(const char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
*	Returns -1 if a texture identifier is seen two times
*	Returns -1 if the line containing the texture contains something
*	after the path texture
*/
int	handle_texture(char **texture, char **split, char *id)
{
	if (*texture != NULL)
		return (ret_error(id, DUPLICATE_TEXTURE));
	if (split[2])
		return (ret_error(split[2], INV_CHAR" after texture"));
	*texture = ft_strdup(split[1]);
	return (0);
}

/*
*	Returns -1 if the string contains chars other than digits
*/
int	err_atoui(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		nb = nb * 10;
		nb = nb + (str[i] - 48);
		i++;
	}
	return (nb);
}

/*
*	Find NO, SO, WE, EA, F, C and map.
*	If something else is encoutered, returns -1
*/
int	parse_line(t_mlx *cub, char **split, char **line, int fd)
{
	if (split[0] == NULL)
		return (1);
	if (!ft_strcmp(split[0], "NO"))
		return (handle_texture(&cub->textures.no, split, "NO"));
	if (!ft_strcmp(split[0], "SO"))
		return (handle_texture(&cub->textures.so, split, "SO"));
	if (!ft_strcmp(split[0], "WE"))
		return (handle_texture(&cub->textures.we, split, "WE"));
	if (!ft_strcmp(split[0], "EA"))
		return (handle_texture(&cub->textures.ea, split, "EA"));
	if (!ft_strcmp(split[0], "C"))
		return (handle_color(&cub->scene.ceiling_c, split, "C"));
	if (!ft_strcmp(split[0], "F"))
		return (handle_color(&cub->scene.floor_c, split, "F"));
	if (valid_map_line(cub, *line))
		return (read_map(cub, fd, line));
	return (ret_error(split[0], INV_CHAR));
}
