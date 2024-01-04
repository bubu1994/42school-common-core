/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:59:32 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/04 14:02:06 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_liste(Nombre_l *liste)
{
	while (liste)
	{
		printf("%d) %d\n", liste->pos, liste->nb);
		liste = liste->next;
	}
}

void	free_liste(Nombre_l *liste)
{
	Nombre_l	*temp;

	while (liste)
	{
		temp = liste;
		liste = liste->next;
		free(temp);
	}
}

Nombre_l	*ajout_element_alafin(Nombre_l *liste, int n, int index)
{
	Nombre_l	*elem;
	Nombre_l	*fin;

	elem = malloc(sizeof(Nombre_l));
	if (!elem)
		return (NULL);
	elem->nb = n;
	elem->pos = index;
	elem->next = NULL;
	if (!liste)
		return (elem);
	fin = liste;
	while (fin->next != NULL)
		fin = fin->next;
	fin->next = elem;
	return (liste);
}

Nombre_l	*create_pile(int argc, char **argv)
{
	Nombre_l	*pile;
	int			i;

	i = 1;
	pile = NULL;
	while (i < argc)
	{
		pile = ajout_element_alafin(pile, ft_atoi(argv[i]), i);
		i++;
	}
	return (pile);
}

int	main(int argc, char **argv)
{
	Nombre_l	*a_pile;
	Nombre_l	*b_pile;
	
	if (argc <= 2)
		return (0);
	a_pile = create_pile(argc, argv);
	b_pile = NULL;
	if (argc == 3)
		tri_2(&a_pile);
	else if (argc == 4)
		tri_3(&a_pile);
	else if (argc == 5)
		tri_4(&a_pile, &b_pile);
	else if (argc == 6)
		tri_5(&a_pile, &b_pile);


	printf("\n------- \npile a:\n");
	print_liste(a_pile);
	printf("\npile b:\n");
	print_liste(b_pile);
	free_liste(a_pile);
	free_liste(b_pile);
	return (0);
}