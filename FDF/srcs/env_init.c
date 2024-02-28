/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:53:29 by gentian           #+#    #+#             */
/*   Updated: 2024/02/27 15:29:01 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_zoom(t_data *mlx)
{
	float	x_zoom;
	float	y_zoom;

	x_zoom = (WIDTH - 2 * GAP_W) / mlx->axes.x_extrem;
	y_zoom = (HEIGHT - 2 * GAP_H) / mlx->axes.y_extrem;
	if (x_zoom > y_zoom)
		mlx->zoom = y_zoom;
	else
		mlx->zoom = x_zoom;
}

int	get_xinit(t_data mlx)
{
	int	dx;
	int	res;

	dx = x_tr(mlx.axes.x_extrem, 0, mlx) + x_tr(0, mlx.axes.y_extrem, mlx);
	res = (WIDTH - dx) / 2;
	return (res);
}

int	get_yinit(t_data mlx)
{
	int	dy;
	int	res;

	dy = y_tr(mlx.axes.y_extrem, mlx.axes.x_extrem, mlx);
	res = (HEIGHT - dy) / 2;
	return (res);
}

void	init_env(t_data *mlx)
{
	mlx->alpha = M_PI / 4;
	mlx->beta = 0;
	mlx->gamma = M_PI / 4;
	init_zoom(mlx);
	mlx->alt_scale = 1.0;
	mlx->x_pos = get_xinit(*mlx);
	mlx->y_pos = get_yinit(*mlx);
	mlx->delta_zoom = mlx->zoom / 20;
	mlx->delta_alt = 0.2;
	mlx->color_default = 0xffffff;
	mlx->second_color = 0xffffff;
}

char	***array_of_points(char *file, t_axes axes)
{
	char	***res;
	char	*line;
	int		i;
	int		fd;

	res = malloc(sizeof(char **) * (axes.y_extrem + 2));
	if (!res)
		return (NULL);
	fd = open(file, O_RDONLY);
	fd_open_error(fd);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		res[i] = ft_super_split(line, " \n");
		free(line);
		i++;
	}
	res[i] = NULL;
	close(fd);
	return (res);
}
