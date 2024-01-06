/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createpile_andfree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:23:49 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/06 15:21:31 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_liste(t_list *liste)
{
	t_list	*temp;

	while (liste)
	{
		temp = liste;
		liste = liste->next;
		free(temp);
	}
}

void	free_ar(char **ar, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

t_list	*ajout_element_alafin(t_list *liste, int n, int index)
{
	t_list	*elem;
	t_list	*fin;

	elem = malloc(sizeof(t_list));
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

t_list	*create_pile(char **argv)
{
	t_list	*pile;
	int		i;

	pile = NULL;
	i = 0;
	while (argv[i])
	{
		pile = ajout_element_alafin(pile, ft_atoi(argv[i]), i + 1);
		i++;
	}
	return (pile);
}
