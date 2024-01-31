/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:53:51 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/31 12:13:18 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_lst(t_pos *lst)
{
	t_pos	*temp;

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

t_pos	*add_point_to_lst(t_pos *lst, int a, int b, int c)
{
	t_pos	*elem;
	t_pos	*dernier;

	elem = malloc(sizeof(t_pos));
	if (!elem)
		return (NULL);
	elem->x = a;
	elem->y = b;
	elem->z = c;
	elem->next = NULL;
	if (!lst)
		return (elem);
	dernier = lst;
	while (dernier->next != NULL)
		dernier = dernier->next;
	dernier->next = elem;
	return (lst);
}

void	set_downs_and_rights(t_pos **list)
{
	t_pos	*scan;
	t_pos	*next_down;

	scan = *list;
	next_down = *list;
	while (next_down->y == scan->y)
		next_down = next_down->next;
	while (next_down != NULL)
	{
		scan->down = next_down;
		scan = scan->next;
		next_down = next_down->next;
	}
	scan = *list;
	while (scan->next != NULL)
	{
		if (scan->y == scan->next->y)
			scan->right = scan->next;
		else
			scan->right = NULL;
		scan = scan->next;
	}
}

t_pos	*create_list_pos(int fd)
{
	char	*line;
	char	**tab;
	int		i;
	int		y;
	t_pos	*lst;

	lst = NULL;
	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		tab = ft_super_split(line, " \n");
		i = 0;
		while (tab[i] != NULL)
		{
			lst = add_point_to_lst(lst, i, y, ft_atoi(tab[i]));
			i++;
		}
		y++;
		free_tab(tab);
		free(line);
		line = get_next_line(fd);
	}
	set_downs_and_rights(&lst);
	return (lst);
}
