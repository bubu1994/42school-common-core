/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:24:55 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/22 14:49:55 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./ft_printf/ft_printf.h"
#include "./get_next_line/get_next_line.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

void	print_pile(t_list **pile)
{
	t_list	*scan;

	scan = *pile;
	while (scan)
	{
		ft_printf("%d) %d\n", scan->pos, scan->nb);
		scan = scan->next;
	}
}

void	print_piles(t_list **a_pile, t_list **b_pile)
{
	ft_printf("\npile A\n------\n");
	print_pile(a_pile);
	if (ft_lstsize(*b_pile) != 0)
	{
		ft_printf("\npile B\n------\n");
		print_pile(b_pile);
	}
}

void	do_op_2(char *line, t_list **a_pile, t_list **b_pile)
{
	if (!ft_strcmp(line, "rr\n"))
	{
		rotate(a_pile);
		rotate(b_pile);
	}
	else if (!ft_strcmp(line, "rra\n"))
		rrotate(a_pile);
	else if (!ft_strcmp(line, "rrb\n"))
		rrotate(b_pile);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		rrotate(a_pile);
		rrotate(b_pile);
	}
	else
	{
		ft_printf("Error\n");
		return ;
	}
}

void	do_op(char *line, t_list **a_pile, t_list **b_pile)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap(*a_pile);
	else if (!ft_strcmp(line, "sb\n"))
		swap(*b_pile);
	else if (!ft_strcmp(line, "ss\n"))
	{
		swap(*a_pile);
		swap(*b_pile);
	}
	else if (!ft_strcmp(line, "pa\n"))
		push(b_pile, a_pile);
	else if (!ft_strcmp(line, "pb\n"))
		push(a_pile, b_pile);
	else if (!ft_strcmp(line, "ra\n"))
		rotate(a_pile);
	else if (!ft_strcmp(line, "rb\n"))
		rotate(b_pile);
	else
		do_op_2(line, a_pile, b_pile);
}
