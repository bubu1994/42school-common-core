/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaumann <sbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:25:21 by sbaumann          #+#    #+#             */
/*   Updated: 2025/03/07 15:50:59 by sbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_minimap(t_mlx *cub)
{
	cub->mini_map_flag = 0;
	cub->fov_flag = 0;
	cub->grid_flag = 0;
}

static void	init_textures(t_mlx *cub)
{
	cub->textures.no = NULL;
	cub->textures.so = NULL;
	cub->textures.we = NULL;
	cub->textures.ea = NULL;
	cub->textures.door = "./textures/doubleporte.xpm";
	cub->textures.no_img.img_ptr = NULL;
	cub->textures.so_img.img_ptr = NULL;
	cub->textures.we_img.img_ptr = NULL;
	cub->textures.ea_img.img_ptr = NULL;
	cub->textures.door_img.img_ptr = NULL;
}

void	init(t_mlx *cub)
{
	int	i;

	i = -1;
	while (++i < 256)
		cub->keys[i] = 0;
	bonus_or_not_bonus(cub);
	cub->ptr = NULL;
	cub->window = NULL;
	cub->image.img_ptr = NULL;
	cub->cam.x = 0;
	cub->cam.y = 0;
	cub->scene.map = NULL;
	cub->scene.w_map = 0;
	cub->scene.h_map = 0;
	cub->scene.m_scale = 0;
	cub->scene.ceiling_c = 0;
	cub->scene.floor_c = 0;
	cub->last_time = 0;
	init_minimap(cub);
	init_textures(cub);
}
