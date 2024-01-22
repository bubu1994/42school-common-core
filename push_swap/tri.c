/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:23:43 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/07 08:37:21 by gebuqaj          ###   ########.fr       */
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

void	trier(t_list **a_pile, t_list **b_pile, int size)
{
	int	n;

	n = size;
	if (n == 2)
		tri_2(a_pile);
	while (n > 3)
	{
		put_min_at_top(a_pile);
		if (!pile_is_sorted(a_pile))
			push_b(a_pile, b_pile);
		n--;
	}
	tri_3(a_pile);
	while (!(n == size))
	{
		push_a(b_pile, a_pile);
		n++;
	}
}

void	put_min_at_top(t_list **pile)
{
	t_list	*scan;
	int		size;
	int		min;

	min = get_min(pile);
	size = ft_lstsize(*pile);
	scan = *pile;
	while (scan && !(scan->nb == min && scan->pos == 1))
	{
		if (scan->nb == min)
		{
			if (scan->pos <= size / 2)
				rotate_a(pile);
			else
				rrotate_a(pile);
			scan = *pile;
		}
		scan = scan->next;
	}
}
