/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:18:04 by sbaumann          #+#    #+#             */
/*   Updated: 2025/03/11 10:31:21 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
*	Handles the vertical hit case (face == 0)
*/
void	vertical_hit(t_mlx *cub, t_cal *a, int i, double ray_ang)
{
	cub->rays[i].length = fabs(a->side_w - a->dist_w);
	cub->rays[i].dist_perp = cos(fabs(ray_ang - cub->cam.angle))
		* fabs(a->side_w - a->dist_w);
	cub->rays[i].hit_x = a->map_x;
	cub->rays[i].hit_y = cub->cam.y - a->sin * cub->rays[i].length;
	if (a->dir_x > 0)
		cub->rays[i].face_hit = 'W';
	else
		cub->rays[i].face_hit = 'E';
}

/*	
*	Handles the horizontal hit case (face != 0)
*/
void	horizontal_hit(t_mlx *cub, t_cal *a, int i, double ray_ang)
{
	cub->rays[i].length = fabs(a->side_h - a->dist_h);
	cub->rays[i].dist_perp = cos(fabs(ray_ang - cub->cam.angle))
		* fabs(a->side_h - a->dist_h);
	cub->rays[i].hit_y = a->map_y;
	cub->rays[i].hit_x = cub->cam.x + a->cos * cub->rays[i].length;
	if (a->dir_y > 0)
		cub->rays[i].face_hit = 'N';
	else
		cub->rays[i].face_hit = 'S';
}

/*
*	Main function to set ray data
*/
void	set_ray_data(t_mlx *cub, double ray_ang, t_cal *a, int i)
{
	cub->rays[i].ang = ray_ang;
	if (a->face == 0)
		vertical_hit(cub, a, i, ray_ang);
	else
		horizontal_hit(cub, a, i, ray_ang);
	if (cub->scene.map[a->map_y][a->map_x] == '2')
		cub->rays[i].door = true;
	else
		cub->rays[i].door = false;
}

void	other_calculations(t_mlx *cub, t_cal *a)
{
	if (a->sin == 0)
		a->dist_h = INFINITY;
	else 
		a->dist_h = fabs(1 / a->sin);
	if (a->cos > 0)
	{
		a->dir_x = 1;
		a->side_w = (a->map_x + 1 - cub->cam.x) * a->dist_w;
	}
	else
	{
		a->dir_x = -1;
		a->side_w = (cub->cam.x - a->map_x) * a->dist_w;
	}
	if (a->sin > 0)
	{
		a->dir_y = -1;
		a->side_h = (cub->cam.y - a->map_y) * a->dist_h;
	}
	else
	{
		a->dir_y = 1;
		a->side_h = (a->map_y + 1 - cub->cam.y) * a->dist_h;
	}
}
