/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:41:11 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/27 09:41:18 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

#define STEP_SIZE 100

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx_data
{
	void	*ptr;
	void	*win;
	t_data	*img;
}	t_mlx_data;

void	my_putpixel(t_data *img, int x, int y, int color)
{
	int	decalage;

	decalage = (img->line_length * y) + ((img->bits_per_pixel / 8) * x);
	*((unsigned int *)(decalage + img->addr)) = color;
}

void	square_50(t_data *img, int x, int y, int color)
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
			my_putpixel(img, a, b, color);
			a++;
		}
		b++;
	}
}

int	move_square(int key, t_mlx_data *data)
{
	static int	x = 450;
	static int	y = 450;

	square_50(data->img, x, y, 0x000000);
	if (key == 123)
		x -= STEP_SIZE;
	else if (key == 124)
		x += STEP_SIZE;
	else if (key == 126)
		y -= STEP_SIZE;
	else if (key == 125)
		y += STEP_SIZE;
	square_50(data->img, x, y, 0xFFFFFF);
	mlx_put_image_to_window(data->ptr, data->win, data->img->img, 0, 0);

	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	mlx;
	t_data	my_img;
	
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 900, 900, "FENETRRRRREUH");
	my_img.img = mlx_new_image(mlx.ptr, 900, 900);
	my_img.addr = mlx_get_data_addr(my_img.img, &my_img.bits_per_pixel, &my_img.line_length, &my_img.endian);

	mlx.img = &my_img;
	mlx_key_hook(mlx.win, move_square, &mlx);
	mlx_loop(mlx.ptr);
}