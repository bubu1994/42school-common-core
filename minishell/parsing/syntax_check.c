/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:05:32 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/10/06 12:30:42 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	wrong_pipes(t_tok *token)
{
	while (token && token->value == ' ')
		token = token->next;
	if (token && token->type[0] == '|')
		return (1);
	while (token)
	{
		if (token->type[0] == '|')
		{
			token = token->next;
			if (!token)
				return (0);
			while (token && token->value == ' ')
				token = token->next;
			if (!token)
				return (0);
			if (token && token->type[0] == '|')
				return (1);
		}
		token = token->next;
	}
	return (0);
}

int	wrong_sup(t_tok *token)
{
	while (token)
	{
		if (token->type[0] == '>')
		{
			token = token->next;
			if (!token)
				return (1);
			if (token->type[0] == '>')
				token = token->next;
			while (token && token->value == ' ')
				token = token->next;
			if (token == NULL || token->type[0] == '<'
				|| token->type[0] == '|' || token->type[0] == '>')
				return (1);
		}
		token = token->next;
	}
	return (0);
}

int	wrong_inf(t_tok *token)
{
	while (token)
	{
		if (token->type[0] == '<')
		{
			token = token->next;
			if (!token)
				return (1);
			if (token->type[0] == '<')
				token = token->next;
			while (token && token->value == ' ')
				token = token->next;
			if (token == NULL || token->type[0] == '>'
				|| token->type[0] == '|' || token->type[0] == '<')
				return (1);
		}
		token = token->next;
	}
	return (0);
}

int	blank_redir(t_tok *token)
{
	while (token)
	{
		if ((token->type[0] == '>' || token->type[0] == '<'))
		{
			token = token->next;
			if (!token)
				return (1);
			if (token->value == ' ')
			{
				while (token->value == ' ')
					token = token->next;
				if (!token || token->type[0] == '<' || token->type[0] == '>')
					return (1);
			}
		}
		token = token->next;
	}
	return (0);
}

int	syntax_ok(t_tok *token)
{
	if (wrong_pipes(token) || wrong_sup(token) || wrong_inf(token))
		return (0);
	return (1);
}
