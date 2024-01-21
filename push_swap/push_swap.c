/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:59:32 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/06 15:22:02 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	print_pile(t_list **pile)
{
	t_list	*scan;

	scan = *pile;
	while (scan)
	{
		printf("%d) %d\n", scan->pos, scan->nb);
		scan = scan->next;
	}
}

int	main_2(char **argv)
{
	t_list	*a_pile;
	t_list	*b_pile;
	char	**ar;
	int		size_ar;

	size_ar = sizetab(argv[1], ' ');
	ar = ft_split_m(argv[1], ' ');
	if (!(check_args(ar)))
	{
		write(1, "Error\n", 6);
		free_ar(ar, size_ar);
		return (0);
	}
	a_pile = create_pile(ar);
	b_pile = NULL;
	if (ft_lstsize(a_pile) == 2)
		tri_2(&a_pile);
	else
		turk_algo(&a_pile, &b_pile);
	free_liste(a_pile);
	free_liste(b_pile);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a_pile;
	t_list	*b_pile;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		main_2(argv);
		return (0);
	}
	if (!(check_args(argv + 1)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	a_pile = create_pile(argv + 1);
	b_pile = NULL;
	if (argc == 3)
		tri_2(&a_pile);
	else
		turk_algo(&a_pile, &b_pile);
	free_liste(a_pile);
	free_liste(b_pile);
	return (0);
}
