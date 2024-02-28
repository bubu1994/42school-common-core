/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:24:20 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/02/27 15:28:41 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_initialise(t_data *mlx)
{
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "FDF");
	mlx->img.img_ptr = mlx_new_image(mlx->ptr, WIDTH + 1, HEIGHT + 1);
	mlx->img.img_pixels_ptr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_len, &mlx->img.endian);
}

void	init_void_file(t_data *mlx)
{
	mlx->alpha = 0;
	mlx->beta = 0;
	mlx->gamma = 0;
	mlx->zoom = 1;
	mlx->alt_scale = 1.0;
	mlx->x_pos = 0;
	mlx->y_pos = 0;
	mlx->delta_zoom = mlx->zoom / 10;
	mlx->delta_alt = 0.2;
	mlx->color_default = 0xffffff;
	mlx->second_color = 0xffffff;
}

void	init_one_point_file(t_data *mlx)
{
	mlx->alpha = 0;
	mlx->beta = 0;
	mlx->gamma = 0;
	mlx->zoom = 1;
	mlx->alt_scale = 1.0;
	mlx->x_pos = WIDTH / 2;
	mlx->y_pos = HEIGHT / 2;
	mlx->delta_zoom = mlx->zoom / 10;
	mlx->delta_alt = 0.2;
	mlx->color_default = 0xffffff;
	mlx->second_color = 0xffffff;
	put_my_pixel(&mlx->img, mlx->x_pos, mlx->y_pos, mlx->color_default);
}

void	norminette_is_my_friend(t_data mlx)
{
	put_rectangle(mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	put_texts(mlx);
	mlx_hook(mlx.win, 2, 0, my_keypress, &mlx);
	mlx_hook(mlx.win, 17, 0, close_x, &mlx);
	mlx_mouse_hook(mlx.win, hook_mouse, &mlx);
	mlx_loop(mlx.ptr);
}

int	main(int argc, char **argv)
{
	t_data	mlx;

	if (argc != 2)
		return (0);
	mlx.ptr = mlx_init();
	mlx_initialise(&mlx);
	mlx.axes = get_width_height(argv[1]);
	mlx.points = NULL;
	if ((mlx.axes.x_extrem == -1 && mlx.axes.y_extrem == -1))
		init_void_file(&mlx);
	else
	{
		mlx.points = array_of_points(argv[1], mlx.axes);
		if ((mlx.axes.x_extrem == 0 && mlx.axes.y_extrem == 0))
			init_one_point_file(&mlx);
		else
		{
			init_env(&mlx);
			draw_the_map(mlx);
		}
	}
	norminette_is_my_friend(mlx);
}
/*
code moche, ne pas regarder
*/