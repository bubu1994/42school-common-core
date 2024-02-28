/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:53:48 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/02/27 15:08:49 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fd_open_error(int fd)
{
	if (fd == -1)
	{
		ft_printf("Erreur fichier\n");
		exit(1);
	}
	return ;
}

void	free_tableau(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	size_tableau(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

uint32_t	degrade_color(int a, int b, int i, int steps)
{
	t_color	dif;
	t_color	new;
	float	ratio;

	ratio = (float)i / (float)steps;
	dif.r = ((a >> 24) & 0xFF) - ((b >> 24) & 0xFF);
	dif.g = ((a >> 16) & 0xFF) - ((b >> 16) & 0xFF);
	dif.b = ((a >> 8) & 0xFF) - ((b >> 8) & 0xFF);
	dif.a = (a & 0xFF) - (b & 0xFF);
	new.r = ((a >> 24) & 0xFF) - (dif.r * ratio);
	new.g = ((a >> 16) & 0xFF) - (dif.g * ratio);
	new.b = ((a >> 8) & 0xFF) - (dif.b * ratio);
	new.a = (a & 0xFF) - dif.a * ratio;
	return ((new.r << 24) | (new.g << 16) | (new.b << 8) | new.a);
}

void	free_3d(char ***array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free_tableau(array[i]);
		i++;
	}
	free(array);
}

/*
int main(int argc, char **argv)
{
	t_axes	axes = get_width_height(argv[1]);
	char	***mi_arr = array_of_points(argv[1], axes);
	int	i = 0;
	int j;

	while (mi_arr[i])
	{
		j = 0;
		while (mi_arr[i][j] != NULL)
		{
			printf("|%s|", mi_arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free_3d(mi_arr);
	return (0);
}
*/