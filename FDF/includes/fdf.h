/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:12:02 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/31 15:15:58 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "get_next_line.h"
#include "libft.h"
#include "mlx.h"

#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#define WIDTH_WIN 1200
#define HEIGTH_WIN 900
#define IMG_WIDTH (WIDTH_WIN)
#define IMG_HEIGTH (HEIGTH_WIN)
#define	SCALE_IMG 0.5
#define ALT_SCALE 10
#define Y_ANGLE 0.7854
#define Z_ANGLE 0.5236
#define GAP 300

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_data
{
	void	*ptr;
	void	*win;
	t_img	img;
}	t_data;

typedef struct s_pos
{
	int				x;
	int				y;
	int				z;
	int				color;
	float			i_x;
	float			i_y;
	struct s_pos	*down;
	struct s_pos	*right;
	struct s_pos	*next;
}	t_pos;

void	free_tab(char **tab);
void	free_lst(t_pos *lst);
t_pos	*add_point_to_lst(t_pos *lst, int a, int b, int c);
t_pos	*create_list_pos(int fd);
char	**ft_super_split(char *str, char *charset);
t_pos	*last_elem(t_pos **list);
float	gap_p(t_pos **list, char c);

void	put_square_10(t_img *img, int x, int y, int color);
void	put_list_into_pixels(t_pos **list, t_img img);


void	put_my_pixel(t_img *img, int x, int y, int color);
void	spread_the_points(t_pos **list);
void	center_points_in_image(t_pos **list);





# endif