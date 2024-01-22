/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulling_from_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:51:49 by marvin            #+#    #+#             */
/*   Updated: 2024/01/19 08:51:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*get_min_target(t_list *elem, t_list **pile)
{
	t_list	*scan;
	t_list	*target;
	int		min;

	scan = *pile;
	min = scan->nb;
	target = scan;
	while (scan->next)
	{
		if (min > scan->next->nb)
		{
			min = scan->next->nb;
			target = scan->next;
		}
		scan = scan->next;
	}
	return (target);
}

t_list	*get_target_of_b(t_list *elem, t_list **a_pile)
{
	t_list	*scan;
	t_list	*target;
	int		valeur;

	scan = *a_pile;
	target = NULL;
	valeur = 2147483647;
	while (scan)
	{
		if (elem->nb < scan->nb && valeur > scan->nb)
		{
			valeur = scan->nb;
			target = scan;
		}
		scan = scan->next;
	}
	if (target == NULL)
		target = get_min_target(elem, a_pile);
	return (target);
}

void	set_targets_of_b(t_list **a_pile, t_list **b_pile)
{
	t_list	*scan;

	scan = *b_pile;
	while (scan)
	{
		scan->target = get_target_of_b(scan, a_pile);
		scan = scan->next;
	}
}
