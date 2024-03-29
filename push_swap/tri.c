/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:23:43 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/22 09:04:44 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_2(t_list **a_pile)
{
	if ((*a_pile)->nb > (*a_pile)->next->nb)
		swap_a(*a_pile);
}

void	tri_3(t_list **a_pile)
{
	t_list	*scan;
	int		max;
	int		min;

	scan = *a_pile;
	max = get_max(&scan);
	min = get_min(&scan);
	while (!pile_is_sorted(&scan))
	{
		while (scan)
		{
			if (scan->nb == max && scan->pos == 1)
				rotate_a(a_pile);
			if (scan->nb == min && scan->pos == 2)
				swap_a(*a_pile);
			if (scan->nb == max && scan->pos == 2)
				rrotate_a(a_pile);
			scan = scan->next;
		}
		scan = *a_pile;
	}
}
