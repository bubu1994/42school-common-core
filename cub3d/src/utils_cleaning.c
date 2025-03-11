/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cleaning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:50:29 by gebuqaj           #+#    #+#             */
/*   Updated: 2025/03/11 13:26:44 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	click_x(t_mlx *cub)
{
	destruct(cub);
	return (0);
}

int	ret_error(char *id, char *error)
{
	printf("Error\n");
	printf("%s", error);
	if (id)
		printf(": '%s'", id);
	printf("\n");
	return (-1);
}

void	destruct(t_mlx *cub)
{
	array_free(cub->scene.map);
	if (cub->textures.no)
		free(cub->textures.no);
	if (cub->textures.so)
		free(cub->textures.so);
	if (cub->textures.we)
		free(cub->textures.we);
	if (cub->textures.ea)
		free(cub->textures.ea);
	if (cub->textures.no_img.img_ptr)
		mlx_destroy_image(cub->ptr, cub->textures.no_img.img_ptr);
	if (cub->textures.so_img.img_ptr)
		mlx_destroy_image(cub->ptr, cub->textures.so_img.img_ptr);
	if (cub->textures.we_img.img_ptr)
		mlx_destroy_image(cub->ptr, cub->textures.we_img.img_ptr);
	if (cub->textures.ea_img.img_ptr)
		mlx_destroy_image(cub->ptr, cub->textures.ea_img.img_ptr);
	if (cub->image.img_ptr)
		mlx_destroy_image(cub->ptr, cub->image.img_ptr);
	if (cub->textures.door_img.img_ptr)
		mlx_destroy_image(cub->ptr, cub->textures.door_img.img_ptr);
	if (cub->window)
	{
		mlx_destroy_window(cub->ptr, cub->window);
		mlx_destroy_display(cub->ptr);
		free(cub->ptr);
	}
	exit (0);
}

void	array_free(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
}
