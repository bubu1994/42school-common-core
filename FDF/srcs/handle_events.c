/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:57:43 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/02/27 15:11:45 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_color_and_rotate(int key, t_data *mlx)
{
	if (key == B)
	{
		mlx->color_default = 0x257C00;
		mlx->second_color = 0x78FF3D;
	}
	if (key == V)
	{
		mlx->color_default = 0xCC0000;
		mlx->second_color = 0xFF9999;
	}
	if (key == N)
	{
		mlx->color_default = 0x0000ff;
		mlx->second_color = 0x17FFFF;
	}
	if (key == C)
	{
		mlx->color_default = 0xFFFFFF;
		mlx->second_color = 0xFFFFFF;
	}
}

void	rotate_da_ting(int key, t_data *mlx)
{
	if (key == W)
		mlx->alpha += D_ANG;
	if (key == Q)
		mlx->alpha -= D_ANG;
	if (key == S)
		mlx->beta += D_ANG;
	if (key == A)
		mlx->beta -= D_ANG;
	if (key == Z)
		mlx->gamma += D_ANG;
	if (key == X)
		mlx->gamma -= D_ANG;
}

void	move_and_alt(int key, t_data *mlx)
{
	if (key == LEFT_A)
		mlx->x_pos -= MOVE_A;
	if (key == UP_A)
		mlx->y_pos -= MOVE_A;
	if (key == RIGHT_A)
		mlx->x_pos += MOVE_A;
	if (key == DOWN_A)
		mlx->y_pos += MOVE_A;
	if (key == U && mlx->alt_scale < 100)
		mlx->alt_scale += mlx->delta_alt;
	if (key == J && mlx->alt_scale > -100)
		mlx->alt_scale -= mlx->delta_alt;
	if (key == P)
	{
		mlx->alpha = 0;
		mlx->beta = 0;
		mlx->gamma = 0;
	}
	if (key == O)
	{
		mlx->alpha = M_PI / 4;
		mlx->beta = 0;
		mlx->gamma = M_PI / 4;
	}
}

int	my_keypress(int key, t_data *mlx)
{
	draw_empty(*mlx);
	draw_empty_pixel(*mlx);
	move_and_alt(key, mlx);
	change_color_and_rotate(key, mlx);
	rotate_da_ting(key, mlx);
	if (key == ESC_K)
	{
		free_3d(mlx->points);
		mlx_destroy_image(mlx->ptr, mlx->img.img_ptr);
		mlx_destroy_window(mlx->ptr, mlx->win);
		exit(0);
	}
	draw_the_map(*mlx);
	draw_one_pixel(*mlx);
	put_rectangle(*mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	put_texts(*mlx);
	return (0);
}

int	hook_mouse(int key, int x, int y, t_data *mlx)
{
	(void)x;
	(void)y;
	draw_empty(*mlx);
	if (key == 4 && mlx->zoom < 1000)
		mlx->zoom += mlx->delta_zoom;
	if (key == 5 && mlx->zoom - mlx->delta_zoom >= 0)
		mlx->zoom -= mlx->delta_zoom;
	draw_the_map(*mlx);
	put_rectangle(*mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	put_texts(*mlx);
	return (0);
}
