/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets_of_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:21:56 by marvin            #+#    #+#             */
/*   Updated: 2024/01/21 11:21:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*get_max_target(t_list *elem, t_list **pile)
{
	t_list	*scan;
	t_list	*target;
	int		max;

	scan = *pile;
	max = scan->nb;
	target = scan;
	while (scan->next)
	{
		if (max < scan->next->nb)
		{
			max = scan->next->nb;
			target = scan->next;
		}
		scan = scan->next;
	}
	return (target);
}

t_list	*get_target(t_list *elem, t_list **b_pile)
{
	t_list	*scan;
	t_list	*target;
	int		valeur;

	scan = *b_pile;
	target = NULL;
	valeur = -2147483648;
	while (scan)
	{
		if (elem->nb > scan->nb && valeur < scan->nb)
		{
			valeur = scan->nb;
			target = scan;
		}
		scan = scan->next;
	}
	if (target == NULL)
		target = get_max_target(elem, b_pile);
	return (target);
}

void	set_targets(t_list **a_pile, t_list **b_pile)
{
	t_list	*scan;

	scan = *a_pile;
	while (scan)
	{
		scan->target = get_target(scan, b_pile);
		scan = scan->next;
	}
}

int	max_of(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
