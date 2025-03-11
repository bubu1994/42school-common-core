/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:46:53 by gebuqaj           #+#    #+#             */
/*   Updated: 2025/03/08 10:37:44 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
*	if (key == N)
*		cub->fov_flag = !cub->fov_flag;
*/
int	key_press(int key, t_mlx *cub)
{
	if (key == ESC_K)
		destruct(cub);
	if (key == W || key == A || key == S || key == D || key == E || key == R)
		cub->keys[key] = 1;
	if (key == LEFT_A)
		cub->keys[LEFT_A_STATE] = 1;
	if (key == RIGHT_A)
		cub->keys[RIGHT_A_STATE] = 1;
	if (key == M)
		cub->mini_map_flag = !cub->mini_map_flag;
	if (key == B)
		cub->grid_flag = !cub->grid_flag;
	if (key == I)
		print_rays_data(cub);
	if (key == O)
		print_data(cub);
	return (0);
}

int	key_release(int key, t_mlx *cub)
{
	if (key == W || key == A || key == S || key == D || key == E || key == R)
		cub->keys[key] = 0;
	if (key == LEFT_A)
		cub->keys[LEFT_A_STATE] = 0;
	if (key == RIGHT_A)
		cub->keys[RIGHT_A_STATE] = 0;
	return (0);
}

int	mouse_press(int button, int x, int y, t_mlx *cub)
{
	(void)y;
	if (button != 1)
		return (0);
	if (cub->keys[MOUSE_STATE] == 0)
		cub->mouse_pressed_x = x;
	cub->keys[MOUSE_STATE] = 1;
	return (0);
}

int	mouse_release(int button, int x, int y, t_mlx *cub)
{
	(void)y;
	(void)x;
	if (button != 1)
		return (0);
	cub->keys[MOUSE_STATE] = 0;
	return (0);
}

int	track_mouse_and_rotate(t_mlx *cub)
{
	int		mouse_pos_x;
	int		mouse_pos_y;
	double	speed_gradient;

	if (cub->keys[253])
	{
		mlx_mouse_get_pos(cub->ptr, cub->window, &mouse_pos_x, &mouse_pos_y);
		speed_gradient = (double)(mouse_pos_x - cub->mouse_pressed_x) / 10000;
		if (speed_gradient > 0.2)
			speed_gradient = 0.2;
		cub->cam.angle += speed_gradient;
	}
	return (0);
}
