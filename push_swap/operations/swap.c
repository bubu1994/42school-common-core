/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:58:14 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/03 09:16:40 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(Nombre_l *pile)
{
	int	tmp;

	if (ft_lstsize(pile) < 2)
		return ;
	tmp = pile->nb;
	pile->nb = pile->next->nb;
	pile->next->nb = tmp;
}

void	swap_a(Nombre_l *a_pile)
{
	if (ft_lstsize(a_pile) < 2)
		return ;
	swap(a_pile);
	write(1, "sa\n", 3);
}

void	swap_b(Nombre_l	*b_pile)
{
	if (ft_lstsize(b_pile) < 2)
		return ;
	swap(b_pile);
	write(1, "sb\n", 3);
}

void	swap_ss(Nombre_l *a_pile, Nombre_l *b_pile)
{
	swap(a_pile);
	swap(b_pile);
	write(1, "ss\n", 1);
}