/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:23:43 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/04 14:25:03 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_2(Nombre_l **a_pile)
{
	if ((*a_pile)->nb > (*a_pile)->next->nb)
		swap_a(*a_pile);
}

void	tri_3(Nombre_l **a_pile)
{
	Nombre_l	*scan;
	int			max;
	int			min;

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

void	tri_4(Nombre_l **a_pile, Nombre_l **b_pile)
{
	Nombre_l	*scan;
	int			min;

	scan = *a_pile;
	min = get_min(&scan);
	while (scan)
	{
		if (scan->nb == min && scan->pos == 3)
			rrotate_a(a_pile);
		if (scan->nb == min && scan->pos == 4)
			rrotate_a(a_pile);
		scan = scan->next;
	}
	if (!pile_is_sorted(a_pile))
		push_b(a_pile, b_pile);
	tri_3(a_pile);
	push_a(b_pile, a_pile);
}

void	tri_5(Nombre_l **a_pile, Nombre_l **b_pile)
{
	Nombre_l	*scan;
	int			max;
	int			min;

	scan = *a_pile;
	max = get_max(&scan);
	min = get_min(&scan);
	while (scan)
	{
		
	}
}
