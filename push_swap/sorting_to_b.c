/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:00:33 by marvin            #+#    #+#             */
/*   Updated: 2024/01/18 18:00:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	get_min_cost_and_id(t_list *elem, int c, int id)
{
	if (elem->cost > c)
	{
		elem->cost = c;
		elem->op_id = id;
	}
}

void	cost_push(t_list *elem, int a_size, int b_size)
{
	int	rr_rarb;
	int	rra_rb;
	int	ra_rrb;
	int	rrr_rrarrb;

	rr_rarb = max_of(elem->pos, elem->target->pos) - 1;
	rra_rb = a_size - elem->pos + 1 + elem->target->pos - 1;
	ra_rrb = elem->pos - 1 + b_size - elem->target->pos + 1;
	rrr_rrarrb = max_of(a_size - elem->pos, b_size - elem->target->pos) + 1;
	elem->cost = rr_rarb;
	elem->op_id = 1;
	get_min_cost_and_id(elem, rra_rb, 2);
	get_min_cost_and_id(elem, ra_rrb, 3);
	get_min_cost_and_id(elem, rrr_rrarrb, 4);
}

void	set_costs_and_id(t_list **a_pile, t_list **b_pile)
{
	t_list	*scan;

	scan = *a_pile;
	while (scan)
	{
		cost_push(scan, ft_lstsize(*a_pile), ft_lstsize(*b_pile));
		scan = scan->next;
	}
}

t_list	*elem_to_push(t_list **a_pile, t_list **b_pile)
{
	t_list	*elem;
	t_list	*scan;
	int		min_cost;

	scan = *a_pile;
	elem = scan;
	min_cost = 2147483647;
	while (scan)
	{
		if (scan->cost < min_cost)
		{
			min_cost = scan->cost;
			elem = scan;
		}
		scan = scan->next;
	}
	return (elem);
}
