/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_black.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:44:28 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/02/27 15:32:01 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_one_black_line(t_point a, t_point b, t_data mlx)
{
	int		steps;
	float	x;
	float	y;
	int		i;

	i = 0;
	x = x_tr(a.x, a.y, mlx);
	y = y_tr(a.y, a.x, mlx);
	if (abs(x_tr(b.x, b.y, mlx) - x_tr(a.x, a.y, mlx))
		> abs(y_tr(b.y, b.x, mlx) - y_tr(a.y, a.x, mlx)))
		steps = abs(x_tr(b.x, b.y, mlx) - x_tr(a.x, a.y, mlx));
	else
		steps = abs(y_tr(b.y, b.x, mlx) - y_tr(a.y, a.x, mlx));
	a.i_x = (float)(x_tr(b.x, b.y, mlx) - x_tr(a.x, a.y, mlx)) / (float)steps;
	a.i_y = (float)(y_tr(b.y, b.x, mlx) - y_tr(a.y, a.x, mlx)) / (float)steps;
	while (i <= steps)
	{
		if (!((int)x + mlx.x_pos > WIDTH || (int)x + mlx.x_pos < 0
				|| (int)y + mlx.y_pos > HEIGHT || (int)y + mlx.y_pos < 0))
			put_my_pixel(&mlx.img, (int)x + mlx.x_pos, (int)y + mlx.y_pos,
				0x000000);
		x += a.i_x;
		y += a.i_y;
		i++;
	}
}

void	draw_empty(t_data mlx)
{
	t_point	a;
	t_point	b;
	int		x;
	int		y;

	y = 0;
	while (y <= mlx.axes.y_extrem)
	{
		x = 0;
		while (x <= mlx.axes.x_extrem)
		{
			a.x = x;
			a.y = y;
			b.x = x + 1;
			b.y = y;
			if (x < mlx.axes.x_extrem)
				draw_one_black_line(a, b, mlx);
			b.x = x;
			b.y = y + 1;
			if (y < mlx.axes.y_extrem)
				draw_one_black_line(a, b, mlx);
			x++;
		}
		y++;
	}
}

void	draw_one_pixel(t_data mlx)
{
	if (mlx.axes.x_extrem == 0 && mlx.axes.y_extrem == 0)
		put_my_pixel(&mlx.img, mlx.x_pos, mlx.y_pos, mlx.color_default);
	return ;
}

void	draw_empty_pixel(t_data mlx)
{
	if (mlx.axes.x_extrem == 0 && mlx.axes.y_extrem == 0)
		put_my_pixel(&mlx.img, mlx.x_pos, mlx.y_pos, 0x000000);
	return ;
}
