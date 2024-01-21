/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:39:02 by marvin            #+#    #+#             */
/*   Updated: 2024/01/16 15:39:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	set_medians(t_list **pile)
{
	t_list	*scan;
	int		size;

	scan = *pile;
	size = ft_lstsize(*pile);
	while (scan)
	{
		if (scan->pos > (size / 2) + 1)
			scan->above_m = 0;
		else
			scan->above_m = 1;
		scan = scan->next;
	}
}

void	pushing_to_b(t_list **a_pile, t_list **b_pile)
{
	t_list	*elem;

	set_targets(a_pile, b_pile);
	set_costs_and_id(a_pile, b_pile);
	elem = elem_to_push(a_pile, b_pile);
	if (elem->op_id == 1)
		rr_and_ra_or_rb(elem, a_pile, b_pile);
	else if (elem->op_id == 2)
		rra_and_rb(elem, a_pile, b_pile);
	else if (elem->op_id == 3)
		ra_and_rrb(elem, a_pile, b_pile);
	else if (elem->op_id == 4)
		rrr_and_rra_or_rrb(elem, a_pile, b_pile);
	push_b(a_pile, b_pile);
}

void	pushing_to_a(t_list **a_pile, t_list **b_pile)
{
	t_list	*elem;

	elem = *b_pile;
	set_targets_of_b(a_pile, b_pile);
	set_medians(a_pile);
	if (elem->target->above_m)
	{
		while (elem->target->pos > 1)
			rotate_a(a_pile);
	}
	else
	{
		while (elem->target->pos > 1)
			rrotate_a(a_pile);
	}
	push_a(b_pile, a_pile);
}

void	turk_algo(t_list **a_pile, t_list **b_pile)
{
	int	n;
	int	start_size;

	n = ft_lstsize(*a_pile);
	start_size = ft_lstsize(*a_pile);
	while (n != 3 && ft_lstsize(*b_pile) < 2)
	{
		push_b(a_pile, b_pile);
		n--;
	}
	while (n != 3)
	{
		pushing_to_b(a_pile, b_pile);
		n--;
	}
	tri_3(a_pile);
	while (n != start_size)
	{
		pushing_to_a(a_pile, b_pile);
		n++;
	}
	put_min_at_top(a_pile);
}
