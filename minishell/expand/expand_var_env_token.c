/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_env_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:36:46 by sforster          #+#    #+#             */
/*   Updated: 2024/09/26 16:39:36 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_new_tok(t_tok *prem_d, t_tok *new_tok)
{
	t_tok	*tmp;

	if (!new_tok)
		return ;
	tmp = prem_d->next;
	prem_d->next = new_tok;
	new_tok->prev = prem_d;
	while (new_tok->next != NULL)
	{
		new_tok = new_tok->next;
	}
	new_tok->next = tmp;
	if (tmp)
		tmp->prev = new_tok;
	return ;
}

void	add_tok_to_list(t_tok **list, t_tok *new)
{
	t_tok	*tmp;

	if (!*list)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_tok	*add_new_tok_var(t_tok **list, char n, char s)
{
	t_tok	*new;

	(void) list;
	new = malloc(sizeof(t_tok));
	if (!new)
		return (NULL);
	new->value = n;
	new->type = malloc(2);
	if (!new->type)
		return (NULL);
	if (s == '$' && n == ' ')
		new->type[0] = ' ';
	else
		new->type[0] = 'l';
	new->type[1] = '\0';
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_tok	*new_env_tok(t_env *env, char *str, char s)
{
	t_env	*current;
	t_tok	*new_list;
	t_tok	*new_tok;
	int		i;

	i = -1;
	new_list = NULL;
	current = env;
	while (current)
	{
		if (ft_strcmp(current->env, str) == 0)
		{
			while (current->cont[++i])
			{
				new_tok = add_new_tok_var(&new_list, current->cont[i], s);
				if (new_tok)
					add_tok_to_list(&new_list, new_tok);
			}
			break ;
		}
		current = current->next;
	}
	return (new_list);
}
