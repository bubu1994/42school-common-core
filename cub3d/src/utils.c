/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:49:45 by sbaumann          #+#    #+#             */
/*   Updated: 2025/03/11 08:55:42 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
*	Returns time elapsed in microseconds since (01/01/1970 00:00:00 UTC)
*/
long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

char	**copy_arr(char **arr)
{
	char	**res;
	int		i;

	i = 0;
	while (arr[i])
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		res[i] = ft_strdup(arr[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

/*
*	Define scale of the mini map for the minimap to be (1/ratio) of
*	WIDTH or HEIGHT.
*/
int	opti_scaling_minimap(t_data *scene)
{
	int	scale1;
	int	scale2;
	int	ratio;

	ratio = 3;
	scale1 = WIDTH / ratio / scene->w_map;
	scale2 = HEIGHT / ratio / scene->h_map;
	if (scale1 < scale2)
		return (scale1);
	else
		return (scale2);
}

/*
*	Return 1 if the line contains only 0, 1, N, S, E, W and space
*	Change condition for bonus(door or sprites)
*/
int	valid_map_line(t_mlx *cub, const char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (cub->bonus == false)
		{
			if (s[i] != '0' && s[i] != '1' && s[i] != ' '
				&& s[i] != 'N' && s[i] != 'S' && s[i] != 'E' && s[i] != 'W')
				return (0);
		}
		else
		{
			if (s[i] != '0' && s[i] != '1' && s[i] != '2'
				&& s[i] != ' ' && s[i] != 'N' && s[i] != 'S'
				&& s[i] != 'E' && s[i] != 'W')
				return (0);
		}
		i++;
	}
	return (1);
}

double	extract_frac(double n)
{
	double	frac_part;
	double	int_part;

	frac_part = modf(n, &int_part);
	return (frac_part);
}
