/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 08:57:33 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/27 12:29:04 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

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
	*((unsigned int *)(decalage + img->img_pixels_ptr)) = color;
}

void	put_square_10(t_img *img, int x, int y, int color)
{
	int	a;
	int	b;

	a = x;
	b = y;
	while (b < y + 10)
	{
		a = x;
		while (a < x + 10)
		{
			put_my_pixel(img, a, b, color);
			a++;
		}
		b++;
	}
}