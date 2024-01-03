/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:59:21 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/03 10:30:44 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(Nombre_l **lst, Nombre_l *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_delete_front(Nombre_l **lst)
{
	Nombre_l	*tmp;
	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp);
}

void	push(Nombre_l	**src, Nombre_l **dest)
{
	Nombre_l	*haut_pile;
	Nombre_l	*actuel;

	haut_pile = malloc(sizeof(Nombre_l));
	if (!haut_pile || *src == NULL)
		return ;
	haut_pile->nb = (*src)->nb;
	haut_pile->pos = 1;
	ft_lstadd_front(dest, haut_pile);
	ft_delete_front(src);
	actuel = *src;
	while (actuel)
	{
		actuel->pos -= 1;
		actuel = actuel->next;
	}
	actuel = *dest;
	actuel = actuel->next;
	while (actuel)
	{
		actuel->pos += 1;
		actuel = actuel->next;
	}
}

void	push_a(Nombre_l **src, Nombre_l **dest)
{
	if (*src == NULL)
		return ;
	push(src, dest);
	write(1, "pa\n", 3);
}

void	push_b(Nombre_l **src, Nombre_l **dest)
{
	if (*src == NULL)
		return ;
	push(src, dest);
	write(1, "pb\n", 3);
}