/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaumann <sbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:25:46 by gentian           #+#    #+#             */
/*   Updated: 2025/03/07 15:39:22 by sbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
*	Draws a square of 'm_scale' pixels, the first pixel at x,y
*	the fov rays can go through grid between walls
*/
void	scaled_box(t_mlx *cub, int x, int y, int color)
{
	int	ix;
	int	iy;

	ix = 0;
	while (ix < cub->scene.m_scale)
	{
		iy = 0;
		while (iy < cub->scene.m_scale)
		{
			put_my_pixel(&(cub->image), x + ix, y + iy, color);
			if ((iy + 1 == cub->scene.m_scale
					|| ix + 1 == cub->scene.m_scale) && cub->grid_flag)
				put_my_pixel(&(cub->image), x + ix, y + iy, LIGHT_GREY_GRID);
			iy++;
		}
		ix++;
	}
}

/*
*	Casts a ray from miniplayer.
*	The ray stops when the pixel he goes through is color of wall.
*	The ray goes through minimap if its a losange map
*/
void	send_miniray(t_mlx *cub, int start_x, int start_y, float angle)
{
	float	dx;
	float	dy;
	float	x;
	float	y;

	dx = cos(angle);
	dy = -sin(angle);
	x = (float)start_x;
	y = (float)start_y;
	while (1)
	{
		if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0
			|| get_pixel_color(cub, round(x), round(y)) == GREY_WALLS)
			break ;
		put_my_pixel(&cub->image, round(x), round(y), BLACK_RAYS);
		x += dx;
		y += dy;
	}
}

/*
*	Draws 50 lines that represent the FOV of the miniplayer. not mandatory.
*/
void	field_of_view(t_mlx *cub)
{
	double	angle;
	double	end_ang;
	double	da;

	end_ang = cub->cam.angle - FOV / 2;
	angle = cub->cam.angle + FOV / 2;
	da = FOV / 50;
	while (angle >= end_ang)
	{
		send_miniray(cub, cub->cam.mini_x, cub->cam.mini_y, angle);
		angle -= da;
	}
}

/*
*	Places a square of size 'player_size' whose center is (mini_x, mini_y)
*/
void	place_player_in_minimap(t_mlx *cub)
{
	int	mini_pl_size;
	int	x;
	int	y;
	int	half_size;

	cub->cam.mini_x = EDGE_GAP + cub->cam.x * cub->scene.m_scale;
	cub->cam.mini_y = EDGE_GAP + cub->cam.y * cub->scene.m_scale;
	mini_pl_size = cub->scene.m_scale / 3;
	half_size = mini_pl_size / 2;
	y = cub->cam.mini_y - half_size;
	while (y < cub->cam.mini_y + half_size)
	{
		x = cub->cam.mini_x - half_size;
		while (x < cub->cam.mini_x + half_size)
		{
			put_my_pixel(&cub->image, x, y, RED_PLAYER);
			x++;
		}
		y++;
	}
	if (cub->fov_flag)
		field_of_view(cub);
}

/*
*	Displays minimap
*	- The walls (value of '1') are drawn in grey and scaled
*	- Values other than ' ' (space) are drawn white
*/
void	minimap(t_mlx *cub)
{
	int		x;
	int		y;
	char	**grid;
	int		scale;

	scale = cub->scene.m_scale;
	grid = cub->scene.map;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == '1' || grid[y][x] == '2')
				scaled_box(cub, EDGE_GAP + x * scale,
					EDGE_GAP + y * scale, GREY_WALLS);
			else if (grid[y][x] != ' ')
				scaled_box(cub, EDGE_GAP + x * scale,
					EDGE_GAP + y * scale, WHITE_FLOOR);
			x++;
		}
		y++;
	}
	place_player_in_minimap(cub);
}
