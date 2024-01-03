/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:36:34 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/03 12:18:41 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(Nombre_l **pile)
{
	Nombre_l	*tmp;
	Nombre_l	*last;
	Nombre_l	*actuel;

	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	tmp = *pile;
	tmp->pos = ft_lstsize(*pile);
	(*pile) = (*pile)->next;
	last = *pile;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	actuel = *pile;
	while (actuel->next)
	{
		actuel->pos -= 1;
		actuel = actuel->next;
	}
}

void	rotate_a(Nombre_l **pile)
{
	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	rotate(pile);
	write(1, "ra\n", 3);
}

void	rotate_b(Nombre_l **pile)
{
	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	rotate(pile);
	write(1, "rb\n", 3);
}

void	rotate_ab(Nombre_l **a_pile, Nombre_l **b_pile)
{
	if ((*a_pile == NULL || (*a_pile)->next == NULL) ||
		(*a_pile == NULL || (*a_pile)->next == NULL))
		return ;
	rotate(a_pile);
	rotate(b_pile);
	write(1, "rr\n", 3);
}