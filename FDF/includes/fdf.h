/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:12:02 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/27 14:02:44 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "get_next_line.h"
#include "libft.h"
#include "mlx.h"

#include <stdio.h>
#include <fcntl.h>

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
	struct s_pos	*next;
}	t_pos;

void	free_tab(char **tab);
void	free_lst(t_pos *lst);
t_pos	*add_point_to_lst(t_pos *lst, int a, int b, int c);
t_pos	*create_list_pos(int fd);


void	put_my_pixel(t_img *img, int x, int y, int color);
void	put_square_10(t_img *img, int x, int y, int color);


# endif