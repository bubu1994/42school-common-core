/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 08:57:33 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/31 14:52:00 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

t_pos	*last_elem(t_pos **list)
{
	t_pos	*scan;

	scan = *list;
	while (scan->next != NULL)
		scan = scan->next;
	return (scan);
}

float	gap_p(t_pos **list, char c)
{
	t_pos	*last;

	last = last_elem(list);
	if (c == 'x')
		return ((IMG_WIDTH / last->x));
	else if (c == 'y')
		return ((IMG_HEIGTH / last->y));
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	put_my_pixel(t_img *img, int x, int y, int color)
{
	int	decalage;

	decalage = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->img_pixels_ptr + decalage)) = color;
}

void	spread_the_points(t_pos **list)
{
	t_pos	*scan;
	t_pos	*last;
	float	gap;

	scan = *list;
	last = last_elem(list);
	if (((float)(IMG_WIDTH - 1) / (float)last->x) > ((float)(IMG_HEIGTH - 1) / (float)last->y))
		gap = (IMG_HEIGTH - 1) / (float)last->y;
	else
		gap = (float)(IMG_WIDTH - 1) / (float)last->x;
	while (scan)
	{
		scan->x = (scan->x * gap) * SCALE_IMG;
		scan->y = (scan->y * gap) * SCALE_IMG;
		scan = scan->next;
	}
}

void	center_points_in_image(t_pos **list)
{
	t_pos	*scan;
	t_pos	*last;
	int		dx;
	int		dy;

	scan = *list;
	last = last_elem(list);
	dx = (IMG_WIDTH - last->x) / 2;
	dy = (IMG_HEIGTH - last->y) / 2;
	while (scan)
	{
		scan->x += dx;
		scan->y += dy;
		scan = scan->next;
	}
}