/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:52:19 by syslive           #+#    #+#             */
/*   Updated: 2024/09/24 09:10:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	preceded_by_heredoc(t_tok *token)
{
	int		res;
	t_tok	*scan;

	res = false;
	scan = token->prev;
	while (scan && (scan->type[0] == 'l' || scan->type[0] == '\''
			|| scan->type[0] == '\"'))
		scan = scan->prev;
	while (scan && (scan->type[0] == ' ' || scan->type[0] == '\t'))
		scan = scan->prev;
	if (scan && scan->prev && scan->type[0] == '<'
		&& scan->prev->type[0] == '<')
		res = true;
	return (res);
}

void	expandables(t_data *data, t_tok *scan, char c)
{
	if (scan->next->value == '?')
		expand_exit_status(data, scan);
	else
		expand_var_env(data, scan, c);
}

void	cancel_solo_dollar(t_tok *token)
{
	while (token)
	{
		if ((token->type[0] == '$' || token->type[0] == 'S')
			&& token->next && (token->next->type[0] == '\''
				|| token->next->type[0] == '\"' || token->next->type[0] == ' '
				|| token->next->type[0] == '\t'))
			token->type[0] = 'l';
		token = token->next;
	}
}

void	expand(t_data *data)
{
	t_tok	*scan;

	scan = data->tokens;
	cancel_solo_dollar(scan);
	while (scan)
	{
		if ((scan->type[0] == '$' || scan->type[0] == 'S')
			&& preceded_by_heredoc(scan))
			scan->type[0] = 'l';
		if ((scan->type[0] == '$' || scan->type[0] == 'S')
			&& scan->next && scan->next->value != ' ')
		{
			expandables(data, scan, scan->type[0]);
			if (!data->tokens)
				return ;
			scan = data->tokens;
		}
		if ((scan->type[0] == '$' || scan->type[0] == 'S')
			&& (!scan->next || scan->next->value == ' '))
			scan->type[0] = 'l';
		if (scan == NULL || scan->next == NULL)
			break ;
		scan = scan->next;
	}
}

void	delete_elem(t_tok **head, t_tok *elem)
{
	if (*head == NULL || elem == NULL)
		return ;
	if (*head == elem)
		*head = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	if (elem->prev)
		elem->prev->next = elem->next;
	elem->prev = NULL;
	elem->next = NULL;
	free(elem->type);
	free(elem);
	elem = NULL;
}
