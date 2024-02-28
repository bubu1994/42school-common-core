/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:01:54 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/02/24 11:35:13 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_rectangle(t_data mlx)
{
	int	i;
	int	k;

	i = 100;
	while (i < 350)
	{
		k = 100;
		while (k < 450)
		{
			if (k == 110 || k == 440 || i == 110 || i == 340)
				put_my_pixel(&mlx.img, i, k, 0xffffff);
			else
				put_my_pixel(&mlx.img, i, k, 0x666666);
			k++;
		}
		i++;
	}
}

void	put_texts(t_data mlx)
{
	char	*zoom_str;
	char	*alt_str;

	zoom_str = ft_weak_ftoa(mlx.zoom);
	alt_str = ft_weak_ftoa(mlx.alt_scale);
	mlx_string_put(mlx.ptr, mlx.win, 120, 120, 0xffffff, "Scroll: zoom +/-");
	mlx_string_put(mlx.ptr, mlx.win, 120, 140, 0xffffff, "Arrows: translate");
	mlx_string_put(mlx.ptr, mlx.win, 120, 160, 0xffffff, "Q/A: rotate alpha");
	mlx_string_put(mlx.ptr, mlx.win, 120, 180, 0xffffff, "A/S: rotate beta");
	mlx_string_put(mlx.ptr, mlx.win, 120, 200, 0xffffff, "Z/X: rotate gamma");
	mlx_string_put(mlx.ptr, mlx.win, 120, 220, 0xffffff, "U/J: altitude +/-");
	mlx_string_put(mlx.ptr, mlx.win, 120, 240, 0xff0000, "V: Rouge feu");
	mlx_string_put(mlx.ptr, mlx.win, 120, 260, 0x00ff00, "B: Vert feuille");
	mlx_string_put(mlx.ptr, mlx.win, 120, 280, 0x0000ff, "N: Bleu ocean");
	mlx_string_put(mlx.ptr, mlx.win, 120, 300, 0xffffff, "C: Blanc neige");
	mlx_string_put(mlx.ptr, mlx.win, 120, 320, 0xffffff, "P: Vue orthogonale");
	mlx_string_put(mlx.ptr, mlx.win, 120, 340, 0xffffff, "O: Vue isometrique");
	mlx_string_put(mlx.ptr, mlx.win, 120, 380, 0xffffff, "Zoom: ");
	mlx_string_put(mlx.ptr, mlx.win, 180, 380, 0xffffff, zoom_str);
	free(zoom_str);
	mlx_string_put(mlx.ptr, mlx.win, 120, 400, 0xffffff, "Alt. scale: ");
	mlx_string_put(mlx.ptr, mlx.win, 240, 400, 0xffffff, alt_str);
	free(alt_str);
}

int	close_x(t_data *mlx)
{
	free_3d(mlx->points);
	mlx_destroy_image(mlx->ptr, mlx->img.img_ptr);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit (0);
}
