/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaumann <sbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:04:56 by sbaumann          #+#    #+#             */
/*   Updated: 2025/03/05 18:29:02 by sbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
*	Returns -1 if a color componant is less 0 or more than 255
*	the color is stored in *color_data
*	If the color is 0, we make it 1.
*	The value 0 is used to check if the data has not been seen
*/
int	parse_color_file(unsigned int *color_data, char **arr)
{
	int	i;
	int	n;

	i = 0;
	while (i < 3)
	{
		n = err_atoui(arr[i]);
		if (n < 0 || n > 255)
			return (ret_error(arr[i], INV_COLOR));
		i++;
	}
	*color_data = ((unsigned int)ft_atoi(arr[0]) << 16)
		| ((unsigned int)ft_atoi(arr[1]) << 8)
		| ((unsigned int)ft_atoi(arr[2]));
	if (*color_data == 0)
		(*color_data)++;
	return (1);
}

/*
*	RGB = "0,255,255"
*	Returns -1 if a comma is misplaced (the string is splited with ',' later)
*/
int	check_rgb(char *rgb)
{
	int	i;

	i = 0;
	if (rgb[i] == ',')
		return (-1);
	while (rgb[i])
	{
		while (ft_isdigit(rgb[i]))
			i++;
		if (rgb[i] == '\0')
			break ;
		if (rgb[i] == ',' && rgb[i + 1] == '\0')
			return (-1);
		i++;
		if (rgb[i] && rgb[i] == ',')
			return (-1);
	}
	return (1);
}

/*
*	Returns -1 if C or F is seen two times.
*	Returns -1 if there is something else than color infos.
*	Returns -1 if a color component is missing.
*	Parses line info in parse_color_file.
*/
int	handle_color(unsigned int *color_data, char **split, char *fc)
{
	char	**split_colors;

	if (*color_data != 0)
		return (ret_error(fc, DUPLICATE_COLOUR));
	if (split[2] || check_rgb(split[1]) == -1)
		return (ret_error(fc, INV_CHAR" after color"));
	split_colors = ft_split(split[1], ',');
	if (!split_colors[0] || !split_colors[1]
		|| !split_colors[2] || split_colors[3])
	{
		array_free(split_colors);
		return (ret_error(fc, INV_COLOR));
	}
	if (parse_color_file(color_data, split_colors) == -1)
	{
		array_free(split_colors);
		return (-1);
	}
	array_free(split_colors);
	return (1);
}
