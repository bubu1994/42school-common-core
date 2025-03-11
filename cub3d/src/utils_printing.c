/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:46:40 by sbaumann          #+#    #+#             */
/*   Updated: 2025/03/11 08:55:48 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		printf("%s\n", arr[i++]);
}

void	print_rays_data(t_mlx *cub)
{
	int	i;

	i = 0;
	printf("player\t x:%f\t y_pos:%f\t angle:%f\n",
		cub->cam.x, cub->cam.y, cub->cam.angle);
	while (i < WIDTH)
	{
		if (i % 150 == 0)
		{
			printf("index %d)\tang:%.10f\t len:%.10f\t",
				i, cub->rays[i].ang, cub->rays[i].length);
			printf("dist_perp:%.10f\tface_hit:%c\thit_pos:%.10f\n",
				cub->rays[i].dist_perp, cub->rays[i].face_hit,
				cub->rays[i].hit_pos);
		}
		i++;
	}
	printf("\n");
}

void	print_data(t_mlx *cub)
{
	printf("no:%s\nso:%s\nwe:%s\nea:%s\n", cub->textures.no, cub->textures.so,
		cub->textures.we, cub->textures.ea);
	printf("floor color: %u\nceiling color: %u\n", cub->scene.floor_c,
		cub->scene.ceiling_c);
	printf("w_map:%d\nh_map:%d\n", cub->scene.w_map, cub->scene.h_map);
	print_arr(cub->scene.map);
	printf("x:%f, y: %f\n", cub->cam.x, cub->cam.y);
	printf("minimap_scale: %d\n", cub->scene.m_scale);
}

int	is_in_safe_distance(t_cam *pos)
{
	if (extract_frac(pos->x) <= SAFE_DISTANCE
		|| extract_frac(pos->x) >= 1.0 - SAFE_DISTANCE
		|| extract_frac(pos->y) <= SAFE_DISTANCE
		|| extract_frac(pos->y) >= 1.0 - SAFE_DISTANCE)
		return (1);
	return (0);
}
