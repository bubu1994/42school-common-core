/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:25:31 by gebuqaj           #+#    #+#             */
/*   Updated: 2025/03/11 08:47:24 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	handle_doors(t_mlx *cub)
{
	double	front_x;
	double	front_y;
	int		map_x;
	int		map_y;

	front_x = cub->cam.x + cub->cam.cos / 2;
	front_y = cub->cam.y - cub->cam.sin / 2;
	map_x = (int)front_x;
	map_y = (int)front_y;
	if (cub->scene.map[map_y][map_x] == '2' && cub->keys[E])
		cub->scene.map[map_y][map_x] = '3';
	if (cub->scene.map[map_y][map_x] == '3' && cub->keys[R]
		&& ((int)cub->cam.x != map_x || (int)cub->cam.y != map_y)
		&& !is_in_safe_distance(&cub->cam))
		cub->scene.map[map_y][map_x] = '2';
}

void	update_pos(t_mlx *cub, double new_x, double new_y)
{
	if (cub->scene.map[(int)cub->cam.y][(int)(new_x + SAFE_DISTANCE)] != '1'
		&& cub->scene.map[(int)cub->cam.y][(int)(new_x - SAFE_DISTANCE)] != '1'
		&& cub->scene.map[(int)cub->cam.y][(int)(new_x + SAFE_DISTANCE)] != '2'
		&& cub->scene.map[(int)cub->cam.y][(int)(new_x - SAFE_DISTANCE)] != '2')
		cub->cam.x = new_x;
	if (cub->scene.map[(int)(new_y + SAFE_DISTANCE)][(int)cub->cam.x] != '1'
		&& cub->scene.map[(int)(new_y - SAFE_DISTANCE)][(int)cub->cam.x] != '1'
		&& cub->scene.map[(int)(new_y + SAFE_DISTANCE)][(int)cub->cam.x] != '2'
		&& cub->scene.map[(int)(new_y - SAFE_DISTANCE)][(int)cub->cam.x] != '2')
		cub->cam.y = new_y;
}

void	deplacement(t_mlx *cub)
{
	double	new_x;
	double	new_y;
	double	move_x;
	double	move_y;

	new_x = cub->cam.x;
	new_y = cub->cam.y;
	move_x = cub->cam.cos * SPEED;
	move_y = cub->cam.sin * SPEED;
	if (cub->keys[W])
	{
		new_x += move_x;
		new_y -= move_y;
	}
	if (cub->keys[S])
	{
		new_x -= move_x;
		new_y += move_y;
	}
	update_pos(cub, new_x, new_y);
}

void	lateral_deplacement(t_mlx *cub)
{
	double	new_x;
	double	new_y;
	double	move_x;
	double	move_y;

	new_x = cub->cam.x;
	new_y = cub->cam.y;
	move_x = cub->cam.cos * SPEED;
	move_y = cub->cam.sin * SPEED;
	if (cub->keys[A])
	{
		new_x -= move_y;
		new_y -= move_x;
	}
	if (cub->keys[D])
	{
		new_x += move_y;
		new_y += move_x;
	}
	update_pos(cub, new_x, new_y);
}

void	update_movement(t_mlx *cub)
{
	if (cub->keys[255] || cub->keys[254] || cub->keys[253])
	{
		if (cub->keys[254])
		{
			cub->cam.angle += ROT_SPEED;
			if (cub->cam.angle > 2 * M_PI)
				cub->cam.angle -= 2 * M_PI;
		}
		if (cub->keys[255])
		{
			cub->cam.angle -= ROT_SPEED;
			if (cub->cam.angle < 0)
				cub->cam.angle += 2 * M_PI;
		}
		cub->cam.cos = cos(cub->cam.angle);
		cub->cam.sin = sin(cub->cam.angle);
	}
	if (cub->keys[W] || cub->keys[S])
		deplacement(cub);
	if (cub->keys[A] || cub->keys[D])
		lateral_deplacement(cub);
	if (cub->keys[E] || cub->keys[R])
		handle_doors(cub);
}
