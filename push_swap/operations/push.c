/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:59:21 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/06 15:16:45 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_delete_front(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp);
}

void	push(t_list	**src, t_list **dest)
{
	t_list	*haut_pile;
	t_list	*actuel;

	haut_pile = malloc(sizeof(t_list));
	if (!haut_pile || *src == NULL)
		return ;
	haut_pile->nb = (*src)->nb;
	haut_pile->pos = 1;
	ft_lstadd_front(dest, haut_pile);
	ft_delete_front(src);
	actuel = *src;
	while (actuel)
	{
		actuel->pos -= 1;
		actuel = actuel->next;
	}
	actuel = *dest;
	actuel = actuel->next;
	while (actuel)
	{
		actuel->pos += 1;
		actuel = actuel->next;
	}
}

void	push_a(t_list **src, t_list **dest)
{
	if (*src == NULL)
		return ;
	push(src, dest);
	write(1, "pa\n", 3);
}

void	push_b(t_list **src, t_list **dest)
{
	if (*src == NULL)
		return ;
	push(src, dest);
	write(1, "pb\n", 3);
}
