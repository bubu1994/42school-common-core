/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:40:41 by marvin            #+#    #+#             */
/*   Updated: 2024/08/18 16:40:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*make_phrase(t_tok *token)
{
	char	*str;
	int		i;
	t_tok	*scan;

	scan = token;
	i = 0;
	while (scan && scan->type[0] != '|')
	{
		scan = scan->next;
		i++;
	}
	str = malloc((sizeof(char) * i) + 1);
	if (!str)
		return (NULL);
	scan = token;
	i = 0;
	while (scan && scan->type[0] != '|')
	{
		str[i] = scan->value;
		scan = scan->next;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	reassign_symb(t_word **words)
{
	t_word	*scan;

	scan = *words;
	while (scan && scan->next)
	{
		if (scan->symb == SUP || scan->symb == SUP_SUP || scan->symb == INF)
			scan->next->symb = FICHIER;
		else if (scan->symb == INF_INF && scan->next->symb == QUOTED)
			scan->next->symb = QUOTED_DELIMITER;
		else if (scan->symb == INF_INF)
			scan->next->symb = DELIMITER;
		scan = scan->next;
	}
}

void	add_new_cmd(t_cmd **list, t_tok *token)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = malloc(sizeof(t_cmd) + 1);
	if (!new)
		return ;
	new->phrase = make_phrase(token);
	new->words = build_words(token);
	reassign_symb(&new->words);
	new->simple_cmd = the_command(new->words);
	new->next = NULL;
	new->prev = NULL;
	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

t_tok	*after_pipe(t_tok *tok)
{
	while (tok && tok->type[0] != '|')
		tok = tok->next;
	if (!tok)
		return (NULL);
	tok = tok->next;
	return (tok);
}

t_cmd	*build_cmds(t_tok *tokens)
{
	t_cmd	*list;

	list = NULL;
	while (tokens)
	{
		add_new_cmd(&list, tokens);
		tokens = after_pipe(tokens);
	}
	return (list);
}
