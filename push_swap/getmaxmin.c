/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmaxmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:55:16 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/04 10:44:09 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(Nombre_l **pile)
{
	Nombre_l	*scan;
	int			max;

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

int	get_min(Nombre_l **pile)
{
	Nombre_l	*scan;
	int			min;
	
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

int	pile_is_sorted(Nombre_l **pile)
{
	Nombre_l	*scan;

	scan = *pile;
	while (scan->next)
	{
		if (scan->nb > scan->next->nb)
			return (0);
		scan = scan->next;
	}
	return (1);
}