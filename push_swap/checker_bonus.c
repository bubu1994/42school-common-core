/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:14:15 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/22 14:48:06 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./ft_printf/ft_printf.h"
#include "./get_next_line/get_next_line.h"

void	checker_bonus(t_list **a_pile, t_list **b_pile)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		do_op(line, a_pile, b_pile);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (pile_is_sorted(a_pile) && ft_lstsize(*b_pile) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main_2(char **argv)
{
	t_list	*a_pile;
	t_list	*b_pile;
	char	**ar;
	int		size_ar;

	if (!ft_strcmp((argv[1]), "-p"))
		argv++;
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
	checker_bonus(&a_pile, &b_pile);
	if (!ft_strcmp(argv[0], "-p"))
		print_piles(&a_pile, &b_pile);
	free_liste(a_pile);
	free_liste(b_pile);
	return (0);
}

void	norminette_forever(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_list	*a_pile;
	t_list	*b_pile;

	if (argc == 1)
		return (0);
	if (!ft_strcmp((argv[1]), "-p"))
	{
		argv++;
		argc--;
	}
	if (argc == 2)
	{
		main_2(argv);
		return (0);
	}
	if (!(check_args(argv + 1)))
		norminette_forever();
	a_pile = create_pile(argv + 1);
	b_pile = NULL;
	checker_bonus(&a_pile, &b_pile);
	if (!ft_strcmp(argv[0], "-p"))
		print_piles(&a_pile, &b_pile);
	free_liste(a_pile);
	free_liste(b_pile);
	return (0);
}
