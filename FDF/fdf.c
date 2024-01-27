/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:20:26 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/27 14:04:29 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

#define WIDTH_WIN 900
#define HEIGTH_WIN 900
#define GAP 20

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

void	put_list_into_img(t_pos **list, t_img img)
{
	t_pos	*scan;

	scan = *list;
	while (scan)
	{
		if (scan->z == 0)
			put_my_pixel(&img, scan->x * GAP, scan->y * GAP, 0xFFFFFF);
		else
			put_my_pixel(&img, scan->x * GAP, scan->y * GAP, 0x0000FF);
		scan = scan->next;
	}
}

int	main(int argc, char **argv)
{
	t_data	mlx;
	char	*line;
	char	**tab;
	int		fd;
	t_pos	*ma_liste;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH_WIN, HEIGTH_WIN, "Mi ventana");
	mlx.img.img_ptr = mlx_new_image(mlx.ptr, WIDTH_WIN, HEIGTH_WIN);
	mlx.img.img_pixels_ptr = mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bits_per_pixel, &mlx.img.line_len, &mlx.img.endian);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit (1);
	}
	ma_liste = create_list_pos(fd);

	
	put_list_into_img(&ma_liste, mlx.img);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.img_ptr, WIDTH_WIN * 0.1, HEIGTH_WIN * 0.3);
	free_lst(ma_liste);
	mlx_loop(mlx.ptr);
	return (0);
}