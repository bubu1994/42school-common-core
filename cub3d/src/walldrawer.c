/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walldrawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:05:41 by gebuqaj           #+#    #+#             */
/*   Updated: 2025/03/11 09:29:27 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* 
*	endian == 0 (Little endian, e.g., x86), 
*	endian == 1 (Big endian, e.g., some PowerPC architectures)
*/
unsigned int	get_texture_pixel(t_tex_img *texture, int x, int y)
{
	int				offset;
	unsigned int	color;

	if (!texture || !texture->img_pixels_ptr || x < 0 || x >= texture->width
		|| y < 0 || y >= texture->height)
		return (MAGENTA_DEBUG);
	offset = (y * texture->line_len) + (x * (texture->bits_per_pixel / 8));
	if (texture->endian == 0)
		color = *(unsigned int *)(texture->img_pixels_ptr + offset);
	else
	{
		color = (texture->img_pixels_ptr[offset] << 24)
			| (texture->img_pixels_ptr[offset + 1] << 16)
			| (texture->img_pixels_ptr[offset + 2] << 8)
			| (texture->img_pixels_ptr[offset + 3]);
	}
	return (color);
}

static t_tex_img	*select_texture(char face, t_mlx *cub, bool door)
{
	if (door)
		return (&cub->textures.door_img);
	if (face == 'N')
		return (&cub->textures.no_img);
	else if (face == 'S')
		return (&cub->textures.so_img);
	else if (face == 'E')
		return (&cub->textures.ea_img);
	else if (face == 'W')
		return (&cub->textures.we_img);
	return (NULL);
}

static int	compute_tex_x(t_mlx *cub, int col, t_tex_img *texture)
{
	int	tex_x;

	if (cub->rays[col].face_hit == 'N' || cub->rays[col].face_hit == 'S')
		tex_x = (int)(cub->rays[col].hit_x * texture->width) % texture->width;
	else
		tex_x = (int)(cub->rays[col].hit_y * texture->width) % texture->width;
	return (tex_x);
}

static void	draw_column(t_mlx *cub, int col)
{
	int			wall_height;
	int			tex_x;
	int			tex_y;
	int			y;
	t_tex_img	*texture;

	wall_height = HEIGHT / cub->rays[col].dist_perp;
	texture = select_texture(cub->rays[col].face_hit, cub, cub->rays[col].door);
	if (!texture)
		return ;
	tex_x = compute_tex_x(cub, col, texture);
	y = 0;
	while (y <= wall_height)
	{
		tex_y = (int)((double)y / wall_height * texture->height);
		if (tex_y >= texture->height)
			tex_y = texture->height - 1;
		put_my_pixel(&cub->image, col, y + ((HEIGHT - wall_height) / 2),
			get_texture_pixel(texture, tex_x, tex_y));
		y++;
	}
}

void	wall_drawer(t_mlx *cub)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		draw_column(cub, i);
		i++;
	}
}
