/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:54:27 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/09/12 11:39:49 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_special(char c)
{
	char	*special_chars;
	int		i;

	special_chars = " \t$|\"\'><";
	i = 0;
	while (special_chars[i])
	{
		if (special_chars[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*assign_type(char c)
{
	char	*res;

	res = malloc(2);
	if (!res)
		return (NULL);
	if (is_special(c))
		res[0] = c;
	else
		res[0] = 'l';
	res[1] = '\0';
	return (res);
}

static t_tok	*new_elem(char c)
{
	t_tok	*res;

	res = malloc(sizeof(t_tok));
	if (!res)
		return (NULL);
	res->value = c;
	res->type = assign_type(c);
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

static void	add_back(t_tok **lst, t_tok *new)
{
	t_tok	*back;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	back = *lst;
	while (back->next)
		back = back->next;
	back->next = new;
	new->prev = back;
}

t_tok	*tokenise(char *input)
{
	t_tok	*res;
	t_tok	*new;
	int		i;

	res = NULL;
	i = 0;
	while (input[i])
	{
		new = new_elem(input[i]);
		add_back(&res, new);
		i++;
	}
	return (res);
}
