/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_3d_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:44:30 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/02/27 15:30:25 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_stuffs(char **tab, char *line)
{
	free_tableau(tab);
	free(line);
}

void	free_stuffs_and_check_x_extrem(char **tab, char *line, t_axes res)
{
	free_tableau(tab);
	free(line);
	if (res.temp_x != res.x_extrem)
	{
		close(res.fd);
		ft_printf("Erreur fichier\n");
		exit(1);
	}
	return ;
}

void	check_first_line(char *line, t_axes *res)
{
	if (line == NULL)
	{
		close(res->fd);
		res->x_extrem = -1;
		res->y_extrem = -1;
	}
	res->y_extrem = -1;
}

t_axes	get_width_height(char *file)
{
	t_axes	res;
	char	*line;
	char	**tab;

	res.fd = open(file, O_RDONLY);
	fd_open_error(res.fd);
	line = get_next_line(res.fd);
	check_first_line(line, &res);
	if (line == NULL)
		return (res);
	tab = ft_super_split(line, " \n");
	res.x_extrem = size_tableau(tab) - 1;
	free_stuffs(tab, line);
	while (1)
	{
		res.y_extrem++;
		line = get_next_line(res.fd);
		if (line == NULL)
			break ;
		tab = ft_super_split(line, " \n");
		res.temp_x = size_tableau(tab) - 1;
		free_stuffs_and_check_x_extrem(tab, line, res);
	}
	close(res.fd);
	return (res);
}
