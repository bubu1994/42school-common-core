/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:16:50 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/06 15:22:11 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrotate(t_list **pile)
{
	t_list	*last;
	t_list	*avant_dernier;
	t_list	*actuel;
	int		i;

	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	avant_dernier = *pile;
	while (avant_dernier->next->next != NULL)
		avant_dernier = avant_dernier->next;
	last = avant_dernier->next;
	avant_dernier->next = NULL;
	last->next = *pile;
	*pile = last;
	actuel = *pile;
	i = 1;
	while (actuel)
	{
		actuel->pos = i;
		actuel = actuel->next;
		i++;
	}
}

void	rrotate_a(t_list **pile)
{
	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	rrotate(pile);
	write(1, "rra\n", 4);
}

void	rrotate_b(t_list **pile)
{
	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	rrotate(pile);
	write(1, "rrb\n", 4);
}

void	rrotate_ab(t_list **a_pile, t_list **b_pile)
{
	if ((*a_pile == NULL || (*a_pile)->next == NULL)
		|| (*a_pile == NULL || (*a_pile)->next == NULL))
		return ;
	rrotate(a_pile);
	rrotate(b_pile);
	write(1, "rrr\n", 4);
}
