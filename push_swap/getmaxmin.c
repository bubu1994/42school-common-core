/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmaxmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:55:16 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/06 15:21:47 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list **pile)
{
	t_list	*scan;
	int		max;

	scan = *pile;
	max = scan->nb;
	while (scan->next)
	{
		if (max < scan->next->nb)
			max = scan->next->nb;
		scan = scan->next;
	}
	return (max);
}

int	get_min(t_list **pile)
{
	t_list	*scan;
	int		min;

	scan = *pile;
	min = scan->nb;
	while (scan->next)
	{
		if (min > scan->next->nb)
			min = scan->next->nb;
		scan = scan->next;
	}
	return (min);
}

int	pile_is_sorted(t_list **pile)
{
	t_list	*scan;

	scan = *pile;
	while (scan->next)
	{
		if (scan->nb > scan->next->nb)
			return (0);
		scan = scan->next;
	}
	return (1);
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
