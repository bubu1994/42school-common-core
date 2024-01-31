/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:41:11 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/29 16:19:05 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

#define STEP_SIZE 100

void	square_50(t_img *img, int x, int y, int color)
{
	int	a;
	int	b;

	a = x;
	b = y;
	while (b < y + 50)
	{
		a = x;
		while (a < x + 50)
		{
			put_my_pixel(img, a, b, color);
			a++;
		}
		b++;
	}
}

int	move_square(int key, t_data *mlx)
{
	static int	x = 450;
	static int	y = 450;

	square_50(&(mlx->img), x, y, 0x000000);
	if (key == 123)
		x -= STEP_SIZE;
	else if (key == 124)
		x += STEP_SIZE;
	else if (key == 126)
		y -= STEP_SIZE;
	else if (key == 125)
		y += STEP_SIZE;
	square_50(&(mlx->img), x, y, 0xFFFFFF);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img_ptr, 0, 0);

	return (0);
}

int	main(int argc, char **argv)
{
	t_data	mlx;
	t_img	my_img;
	
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 900, 900, "FENETRRRRREUH");
	my_img.img_ptr = mlx_new_image(mlx.ptr, 900, 900);
	my_img.img_pixels_ptr = mlx_get_data_addr(my_img.img_ptr, &my_img.bits_per_pixel, &my_img.line_len, &my_img.endian);

	mlx.img = my_img;
	mlx_key_hook(mlx.win, move_square, &mlx);
	mlx_loop(mlx.ptr);
}