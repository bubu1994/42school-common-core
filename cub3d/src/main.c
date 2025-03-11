/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:30:25 by gebuqaj           #+#    #+#             */
/*   Updated: 2025/03/11 08:53:59 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
*	Main render function
*	Calculats the time elapsed in microseconds since the last frame.
*	If the result is smaller than the desired time interval 
*	(1 second / wanted fps = 1000000 / 30 = 33333 
*	microseconds = 0.033333 seconds), it skips the render
*/
int	render_loop(t_mlx *cub)
{
	if ((get_current_time() - cub->last_time) < (1000000 / 30))
		return (0);
	cub->last_time = get_current_time();
	update_movement(cub);
	track_mouse_and_rotate(cub);
	fill_floor_ceiling(cub);
	raycaster(cub);
	wall_drawer(cub);
	if (cub->mini_map_flag)
		minimap(cub);
	mlx_put_image_to_window(cub->ptr, cub->window, cub->image.img_ptr, 0, 0);
	return (0);
}

/*
*	cub->textures.no_img.img_ptr = mlx_xpm_file_to_image(cub->ptr,
*	cub->textures.no, NULL, NULL);
*	ne fonctionne pas à des pointeurs NULL !
*/
int	create_window_images(t_mlx *cub)
{
	cub->ptr = mlx_init();
	cub->window = mlx_new_window(cub->ptr, WIDTH, HEIGHT, "cub3d");
	cub->image.img_ptr = mlx_new_image(cub->ptr, WIDTH, HEIGHT);
	cub->image.img_pixels_ptr = mlx_get_data_addr(cub->image.img_ptr,
			&cub->image.bits_per_pixel, &cub->image.line_len,
			&cub->image.endian);
	return (1);
}

/*
*	Press I to display rays data on terminal
*/
int	main(int argc, char **argv)
{
	t_mlx	cub;

	if (argc != 2)
		return (ret_error(NULL, INV_ARGS));
	init(&cub);
	if (parsing(&cub, argv[1]) == -1)
		destruct(&cub);
	if (create_window_images(&cub) == -1)
		destruct(&cub);
	if (load_textures(&cub) == -1)
		destruct(&cub);
	mlx_hook(cub.window, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.window, 3, 1L << 1, key_release, &cub);
	mlx_hook(cub.window, 4, 1L << 2, mouse_press, &cub);
	mlx_hook(cub.window, 5, 1L << 3, mouse_release, &cub);
	mlx_hook(cub.window, 17, 0, click_x, &cub);
	mlx_loop_hook(cub.ptr, render_loop, &cub);
	mlx_loop(cub.ptr);
}
