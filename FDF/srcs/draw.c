/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:28:57 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/02/24 12:33:12 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_my_pixel(t_img *img, int x, int y, int color)
{
	int	decalage;

	decalage = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->img_pixels_ptr + decalage)) = color;
}

int	x_tr(int a, int b, t_data mlx)
{
	int		x;
	int		y;
	float	z;

	z = ft_atoi(mlx.points[b][a]) * mlx.alt_scale * mlx.zoom;
	x = a * mlx.zoom;
	y = b * mlx.zoom;
	x = (z * sin(mlx.beta) + (x * cos(mlx.gamma)
				- y * sin(mlx.gamma)) * cos(mlx.beta));
	return (x);
}

int	y_tr(int b, int a, t_data mlx)
{
	int		x;
	int		y;
	float	z;

	z = ft_atoi(mlx.points[b][a]) * mlx.alt_scale * mlx.zoom;
	x = a * mlx.zoom;
	y = b * mlx.zoom;
	y = ((x * sin(mlx.gamma) + y * cos(mlx.gamma)) * cos(mlx.alpha)
			- (z * cos(mlx.beta) - (x * cos(mlx.gamma) - y * sin(mlx.gamma))
				* sin(mlx.beta)) * sin(mlx.alpha));
	return (y);
}

void	draw_one_line(t_point a, t_point b, t_data mlx)
{
	float	x;
	float	y;
	int		i;

	i = 0;
	x = x_tr(a.x, a.y, mlx);
	y = y_tr(a.y, a.x, mlx);
	if (abs(x_tr(b.x, b.y, mlx) - x_tr(a.x, a.y, mlx))
		> abs(y_tr(b.y, b.x, mlx) - y_tr(a.y, a.x, mlx)))
		a.steps = abs(x_tr(b.x, b.y, mlx) - x_tr(a.x, a.y, mlx));
	else
		a.steps = abs(y_tr(b.y, b.x, mlx) - y_tr(a.y, a.x, mlx));
	a.i_x = (float)(x_tr(b.x, b.y, mlx) - x_tr(a.x, a.y, mlx)) / (float)a.steps;
	a.i_y = (float)(y_tr(b.y, b.x, mlx) - y_tr(a.y, a.x, mlx)) / (float)a.steps;
	while (i <= a.steps)
	{
		if (!((int)x + mlx.x_pos > WIDTH || (int)x + mlx.x_pos < 0
				|| (int)y + mlx.y_pos > HEIGHT || (int)y + mlx.y_pos < 0))
			put_my_pixel(&mlx.img, (int)x + mlx.x_pos, (int)y + mlx.y_pos,
				degrade_color(pull_color(mlx.points[a.y][a.x], mlx),
					pull_color(mlx.points[b.y][b.x], mlx), i, a.steps));
		x += a.i_x;
		y += a.i_y;
		i++;
	}
}

void	draw_the_map(t_data mlx)
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
				draw_one_line(a, b, mlx);
			b.x = x;
			b.y = y + 1;
			if (y < mlx.axes.y_extrem)
				draw_one_line(a, b, mlx);
			x++;
		}
		y++;
	}
}
/*
a' = (x * cos(mlx.gamma) - y * sin(mlx.gamma));
b' = (x * sin(mlx.gamma) + y * cos(mlx.gamma));
c' = z;

c'' = (z * cos(mlx.beta) - a' * sin(mlx.beta));
a'' = (z * sin(mlx.beta) + a' * cos(mlx.beta));
b'' = b';

b'''= (b'' * cos(mlx.alpha) - c'' * sin(mlx.alpha));
c'''= (b'' * sin(mlx.alpha) + c'' * cos(mlx.alpha));
a''' = a'';
*/
