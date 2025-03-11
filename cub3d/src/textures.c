/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaumann <sbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:33:54 by sbaumann          #+#    #+#             */
/*   Updated: 2025/03/07 14:35:01 by sbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	create_image(t_mlx *cub)
{
	cub->textures.no_img.img_ptr
		= mlx_xpm_file_to_image(cub->ptr, cub->textures.no,
			&cub->textures.no_img.width, &cub->textures.no_img.height);
	if (!cub->textures.no_img.img_ptr)
		return (ret_error(cub->textures.no, XPM_LOAD_FAIL));
	cub->textures.so_img.img_ptr
		= mlx_xpm_file_to_image(cub->ptr, cub->textures.so,
			&cub->textures.so_img.width, &cub->textures.so_img.height);
	if (!cub->textures.so_img.img_ptr)
		return (ret_error(cub->textures.so, XPM_LOAD_FAIL));
	cub->textures.we_img.img_ptr
		= mlx_xpm_file_to_image(cub->ptr, cub->textures.we,
			&cub->textures.we_img.width, &cub->textures.we_img.height);
	if (!cub->textures.we_img.img_ptr)
		return (ret_error(cub->textures.we, XPM_LOAD_FAIL));
	cub->textures.ea_img.img_ptr
		= mlx_xpm_file_to_image(cub->ptr, cub->textures.ea,
			&cub->textures.ea_img.width, &cub->textures.ea_img.height);
	cub->textures.door_img.img_ptr
		= mlx_xpm_file_to_image(cub->ptr, cub->textures.door,
			&cub->textures.door_img.width, &cub->textures.door_img.height);
	if (!cub->textures.ea_img.img_ptr)
		return (ret_error(cub->textures.ea, XPM_LOAD_FAIL));
	return (1);
}

static int	get_image_data(t_mlx *cub)
{
	cub->textures.no_img.img_pixels_ptr
		= mlx_get_data_addr(cub->textures.no_img.img_ptr,
			&cub->textures.no_img.bits_per_pixel,
			&cub->textures.no_img.line_len, &cub->textures.no_img.endian);
	cub->textures.so_img.img_pixels_ptr
		= mlx_get_data_addr(cub->textures.so_img.img_ptr,
			&cub->textures.so_img.bits_per_pixel,
			&cub->textures.so_img.line_len, &cub->textures.so_img.endian);
	cub->textures.we_img.img_pixels_ptr
		= mlx_get_data_addr(cub->textures.we_img.img_ptr,
			&cub->textures.we_img.bits_per_pixel,
			&cub->textures.we_img.line_len, &cub->textures.we_img.endian);
	cub->textures.ea_img.img_pixels_ptr
		= mlx_get_data_addr(cub->textures.ea_img.img_ptr,
			&cub->textures.ea_img.bits_per_pixel,
			&cub->textures.ea_img.line_len, &cub->textures.ea_img.endian);
	cub->textures.door_img.img_pixels_ptr
		= mlx_get_data_addr(cub->textures.door_img.img_ptr,
			&cub->textures.door_img.bits_per_pixel,
			&cub->textures.door_img.line_len, &cub->textures.door_img.endian);
	if (!cub->textures.no_img.img_ptr || !cub->textures.so_img.img_ptr
		|| !cub->textures.we_img.img_ptr || !cub->textures.ea_img.img_ptr
		|| !cub->textures.door_img.img_ptr)
		return (-1);
	return (1);
}

int	load_textures(t_mlx *cub)
{
	if (create_image(cub) == -1)
	{
		printf(IMG_FAIL"\n");
		return (-1);
	}
	if (get_image_data(cub) == -1)
	{
		printf(IMG_DATA_FAIL"\n");
		return (-1);
	}
	return (1);
}
