/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:19:19 by marvin            #+#    #+#             */
/*   Updated: 2024/08/14 13:19:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok	*cancel_all_type(t_tok *token)
{
	if (!token)
		return (token);
	while (token)
	{
		if (token->type[0] == '\'')
			break ;
		token->type[0] = 'l';
		token = token->next;
	}
	return (token);
}

t_tok	*cancel_all_but_dollar(t_tok *token)
{
	if (!token)
		return (token);
	while (token)
	{
		if (token->type[0] == '\"')
			break ;
		if (token->type[0] != '$')
			token->type[0] = 'l';
		else
			token->type[0] = 'S';
		token = token->next;
	}
	return (token);
}

int	quoting(t_tok *tokens)
{
	t_tok	*scan;

	scan = tokens;
	while (scan)
	{
		if (scan->type[0] == '\'' || scan->type[0] == '\"')
		{
			if (scan->type[0] == '\'')
				scan = cancel_all_type(scan->next);
			else if (scan->type[0] == '\"')
				scan = cancel_all_but_dollar(scan->next);
		}
		if (scan == NULL)
			return (0);
		scan = scan->next;
	}
	return (1);
}
