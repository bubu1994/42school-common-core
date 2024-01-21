/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_by_median.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:55:31 by marvin            #+#    #+#             */
/*   Updated: 2024/01/18 18:55:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rr_and_ra_or_rb(t_list *elem, t_list **a_pile, t_list **b_pile)
{
	while (elem->pos > 1 && elem->target->pos > 1)
		rotate_ab(a_pile, b_pile);
	while (elem->pos > 1)
		rotate_a(a_pile);
	while (elem->target->pos > 1)
		rotate_b(b_pile);
}

void	rra_and_rb(t_list *elem, t_list **a_pile, t_list **b_pile)
{
	while (elem->pos > 1)
		rrotate_a(a_pile);
	while (elem->target->pos > 1)
		rotate_b(b_pile);
}

void	ra_and_rrb(t_list *elem, t_list **a_pile, t_list **b_pile)
{
	while (elem->pos > 1)
		rotate_a(a_pile);
	while (elem->target->pos > 1)
		rrotate_b(b_pile);
}

void	rrr_and_rra_or_rrb(t_list *elem, t_list **a_pile, t_list **b_pile)
{
	while (elem->pos > 1 && elem->target->pos > 1)
		rrotate_ab(a_pile, b_pile);
	while (elem->pos > 1)
		rrotate_a(a_pile);
	while (elem->target->pos > 1)
		rrotate_b(b_pile);
}
