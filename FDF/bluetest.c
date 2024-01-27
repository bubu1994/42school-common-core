/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:45:43 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/24 13:48:02 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define HEIGHT 800
#define WIDTH 800

#include "./includes/fdf.h"

int main(int argc, char **argv)
{
	void	*connect_mlx;
	void	*window;
	int		x;
	int		y;
	int		color;

	connect_mlx = mlx_init();
	window = mlx_new_window(connect_mlx, 800, 800, "Ventana");

	x = WIDTH * 0.1;
	y = HEIGHT * 0.3;
	color = 0x0000FF;

	while (y < HEIGHT * 0.7)
	{
		x = WIDTH * 0.1;
		while (x < WIDTH * 0.9)
		{
			mlx_pixel_put(connect_mlx, window, x, y, color++);
			x++;
		}
		y++;
	}
	mlx_string_put(connect_mlx, window, WIDTH * 0.2, HEIGHT * 0.2, 0xFFFFFF, "wow");
	mlx_loop(connect_mlx);
}