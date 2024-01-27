/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:51:41 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/24 16:35:38 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

#define WIDTH 600
#define HEIGHT 600
#define STEP_SIZE 5

typedef struct s_mlx_data
{
	void	*ptr;
	void	*win;
}	t_mlx_data;

int	print_key(int key, t_mlx_data *data)
{
	printf("%d\n", key);
	return (0);
}

int	draw(int key, t_mlx_data *data)
{
	static int	x = WIDTH / 2;
	static int	y = HEIGHT / 2;
	int x_size;
	int	y_size;

	if (key == 123)
		x -= STEP_SIZE;
	else if (key == 124)
		x += STEP_SIZE;
	else if (key == 126)
		y -= STEP_SIZE;
	else if (key == 125)
		y += STEP_SIZE;
	x_size = x;
	while (x_size < x + 10)
	{
		y_size = y;
		while (y_size < y + 10)
		{
			mlx_pixel_put(data->ptr, data->win, x_size, y_size, 0xFFFFFF);
			y_size++;
		}
		x_size++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx_data	data;

	data.ptr = mlx_init();
	data.win = mlx_new_window(data.ptr, 600, 600, "Mi ventana");

	mlx_key_hook(data.win, draw, &data);

	mlx_loop(data.ptr);
}