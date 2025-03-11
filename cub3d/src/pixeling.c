/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixeling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:30:07 by gebuqaj           #+#    #+#             */
/*   Updated: 2025/03/11 08:55:29 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_my_pixel(t_img *img, int x, int y, unsigned int color)
{
	int	decalage;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	decalage = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->img_pixels_ptr + decalage)) = color;
}

/*
*	Draws the up half of the screen with ceiling color.
*	Draws the bottom half with floor color
*/
void	fill_floor_ceiling(t_mlx *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
			put_my_pixel(&(cub->image), x++, y, cub->scene.ceiling_c);
		y++;
	}
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			put_my_pixel(&(cub->image), x++, y, cub->scene.floor_c);
		y++;
	}
}

/* 
*	Returns the color of pixel at (x,y)
*/
int	get_pixel_color(t_mlx *cub, int x, int y)
{
	int		offset;
	int		color;
	t_img	*img;

	img = &cub->image;
	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	if (img->endian == 0)
		color = *(unsigned int *)(img->img_pixels_ptr + offset);
	else
	{
		color = (img->img_pixels_ptr[offset] << 24)
			| (img->img_pixels_ptr[offset + 1] << 16)
			| (img->img_pixels_ptr[offset + 2] << 8)
			| (img->img_pixels_ptr[offset + 3]);
	}
	return (color);
}
