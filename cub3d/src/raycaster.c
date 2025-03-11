/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:58:41 by gebuqaj           #+#    #+#             */
/*   Updated: 2025/03/11 09:29:10 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	compute_dist_w(t_cal *a)
{
	if (a->cos == 0)
		a->dist_w = INFINITY;
	else
		a->dist_w = fabs(1 / a->cos);
}

void	cast_ray(t_mlx *cub, double ray_ang, int i, t_cal *a)
{
	a->map_x = (int)cub->cam.x;
	a->map_y = (int)cub->cam.y;
	compute_dist_w(a);
	other_calculations(cub, a);
	while (1)
	{
		if (a->side_w < a->side_h)
		{
			a->side_w += a->dist_w;
			a->map_x += a->dir_x;
			a->face = 0;
		}
		else
		{
			a->side_h += a->dist_h;
			a->map_y += a->dir_y;
			a->face = 1;
		}
		if (cub->scene.map[a->map_y][a->map_x] == '1'
			|| cub->scene.map[a->map_y][a->map_x] == '2')
			return (set_ray_data(cub, ray_ang, a, i));
	}
}

/*
*	Casts 'WIDTH' rays from the player position so we can fill
*	every vertical line of our window.
*/
void	raycaster(t_mlx *cub)
{
	double	ang;
	double	angle_delta;
	int		i;
	t_cal	a;

	i = 0;
	angle_delta = FOV / (WIDTH - 1);
	ang = cub->cam.angle + (FOV / 2);
	while (i < WIDTH)
	{
		a.cos = cos(ang);
		a.sin = sin(ang);
		cast_ray(cub, ang, i, &a);
		ang -= angle_delta;
		i++;
	}
}
