/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:58:14 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/06 15:17:27 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list *pile)
{
	int	tmp;

	if (ft_lstsize(pile) < 2)
		return ;
	tmp = pile->nb;
	pile->nb = pile->next->nb;
	pile->next->nb = tmp;
}

void	swap_a(t_list *a_pile)
{
	if (ft_lstsize(a_pile) < 2)
		return ;
	swap(a_pile);
	write(1, "sa\n", 3);
}

void	swap_b(t_list	*b_pile)
{
	if (ft_lstsize(b_pile) < 2)
		return ;
	swap(b_pile);
	write(1, "sb\n", 3);
}

void	swap_ss(t_list *a_pile, t_list *b_pile)
{
	swap(a_pile);
	swap(b_pile);
	write(1, "ss\n", 1);
}
