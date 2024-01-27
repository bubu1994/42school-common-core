/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:35:44 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/24 13:50:05 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

typedef struct t_carre
{
	int	x;
	int	y;
	int	size;
	int color;
	struct t_carre *previous;
	struct t_carre *next;
}	t_carre;

t_carre *ft_new(int a, int b, int taille, int rgb)
{
	t_carre	*elem;

	elem = malloc(sizeof(t_carre));
	if (!elem)
		return (NULL);
	elem->x = a;
	elem->y = b;
	elem->size = taille;
	elem->color = rgb;
	elem->next = NULL;
	elem->previous = NULL;
	return (elem);
}

void	ft_add_back(t_carre **lst, t_carre *elem)
{
	t_carre	*scan;

	if (!elem)
		return ;
	if (!lst)
	{
		*lst = elem;
		return ;
	}
	scan = *lst;
	while (scan->next)
		scan = scan->next;
	scan->next = elem;
	elem->previous = scan;
}

void	carre(void *mlx_ptr, void *win_ptr, int x, int y, int size, int color)
{
	int	i;
	int j;

	i = x;
	while (i < x + size)
	{
		j = y;
		while (j < y + size)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
			j++;
		}
		i++;
	}
}

void	carre_struct(void *mlx_ptr, void *win_ptr, t_carre *carre)
{
	int	i;
	int j;

	i = carre->x;
	while (i < carre->x + carre->size)
	{
		j = carre->y;
		while (j < carre->y + carre->size)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, carre->color);
			j++;
		}
		i++;
	}
}


int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 700, 700, "LA LUCAAAAAARNE");
	mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFFFFFF);
	mlx_string_put(mlx_ptr, win_ptr, 200, 100, 0xFF0000, "hola");
	mlx_string_put(mlx_ptr, win_ptr, 150, 200, 0x0000FF, "senor");
	
	i = 0;
	while (i < 700)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 200 + i, 100 + i, 0x00FFAA);
		i++;
	}
	carre(mlx_ptr, win_ptr, 100, 400, 100, 0xFFCD00);

	int x_start = 200;
	int y_start = 600;
	int taille = 50;
	int couleur = 0xF58CE0;
	
	t_carre	*c_list = ft_new(x_start, y_start, taille, couleur);
	t_carre *new;
	int n = 1;
	int diag = 0;
	while (n < 8)
	{
		diag = diag + 70;
		couleur = couleur + 10;
		new = ft_new(x_start + diag, y_start - diag, taille, couleur);
		ft_add_back(&c_list, new);
		n++;
	}
	n = 1;
	while (n < 8)
	{
		carre_struct(mlx_ptr, win_ptr, c_list);
		c_list = c_list->next;
		n++;
	}
	mlx_loop(mlx_ptr);
}