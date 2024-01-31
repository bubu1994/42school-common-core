/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:20:26 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/31 15:08:11 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	print_lst(t_pos **lst)
{
	t_pos	*scan;

	scan = *lst;
	while (scan != NULL)
	{
		printf("x: %d, y: %d, z: %d\n", scan->x, scan->y, scan->z);
		scan = scan->next;
	}
}

void	draw_one_line(t_pos a_point, t_pos b_point, t_img image)
{
	int		steps;
	float	x_moving;
	float	y_moving;
	int		i;

	i = 0;
	x_moving = a_point.x;
	y_moving = a_point.y;
	if (abs(b_point.x - a_point.x) > abs(b_point.y - a_point.y))
		steps = abs(b_point.x - a_point.x);
	else
		steps = abs(b_point.y - a_point.y);
	a_point.i_x = (float)(b_point.x - a_point.x) / (float)steps;
	a_point.i_y = (float)(b_point.y - a_point.y) / (float)steps;
	while (i <= steps)
	{
		put_my_pixel(&image, (int)x_moving, (int)y_moving, 0xFFFFFF);
		x_moving += a_point.i_x;
		y_moving += a_point.i_y;
		i++;
	}
}

void	draw_the_map(t_pos **list, t_img image)
{
	t_pos	*scan;

	scan = *list;
	while (scan->next != NULL)
	{
		if (scan->right != NULL)
			draw_one_line(*scan, *scan->right, image);
		scan = scan->next;
	}
	scan = *list;
	while (scan->down->next != NULL)
	{
		draw_one_line(*scan, *scan->down, image);
		scan = scan->next;
	}
	draw_one_line(*scan, *scan->down, image);
}

void	matrix_the_points(t_pos *point)
{
	int	x_temp;

	while (point)
	{
		x_temp = point->x;
		point->x = point->x - point->y;
		point->y = ((x_temp + point->y) / 2) - point->z;
		point = point->next;
	}
}

int	main(int argc, char **argv)
{
	t_data	mlx;
	int		fd;
	t_pos	*ma_liste;
	
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH_WIN, HEIGTH_WIN, "Mi ventana");
	mlx.img.img_ptr = mlx_new_image(mlx.ptr, IMG_WIDTH, IMG_HEIGTH);
	mlx.img.img_pixels_ptr = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bits_per_pixel, &mlx.img.line_len, &mlx.img.endian);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit (1);
	}
	ma_liste = create_list_pos(fd);
	spread_the_points(&ma_liste);
	matrix_the_points(ma_liste);
	center_points_in_image(&ma_liste);
//	print_lst(&ma_liste);

	draw_the_map(&ma_liste, mlx.img);
	
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	close(fd);
	free_lst(ma_liste);
	mlx_loop(mlx.ptr);
	return (0);
}
