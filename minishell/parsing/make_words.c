/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:42:49 by marvin            #+#    #+#             */
/*   Updated: 2024/08/14 22:42:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	word_size(t_tok *token)
{
	size_t	size;

	size = 0;
	while (token && (token->type[0] == 'l'
			|| token->type[0] == '\'' || token->type[0] == '\''))
	{
		size++;
		token = token->next;
	}
	return (size);
}

t_tok	*l_words(t_tok *token, char **words, bool *word_is_quoted)
{
	char	*word;
	size_t	i;

	word = malloc(sizeof(char) * 255);
	if (!word)
		return (NULL);
	i = 0;
	while (token && i < 255)
	{
		if (!(token->type[0] == '\'' || token->type[0] == '\"'))
			word[i++] = token->value;
		else
			*word_is_quoted = true;
		token = token->next;
		if (token && (token->type[0] == '|' || token->type[0] == '>'
				|| token->type[0] == '<' || token->type[0] == ' '
				|| token->type[0] == '\t'))
			break ;
	}
	word[i] = '\0';
	*words = word;
	return (token);
}

t_tok	*special_word(t_tok *token, char **words)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * 3);
	if (!word)
		return (NULL);
	i = 0;
	while (token && i < 3 && (token->type[0] == '>' || token->type[0] == '<'))
	{
		word[i] = token->value;
		token = token->next;
		i++;
	}
	word[i] = '\0';
	*words = word;
	return (token);
}

size_t	n_chars(t_tok *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type[0] != '|')
	{
		while (tokens && (tokens->type[0] == ' ' || tokens->type[0] == '\t'))
			tokens = tokens->next;
		if (!tokens || tokens->type[0] == '|')
			break ;
		count++;
		if (tokens->type[0] == '>' || tokens->type[0] == '<')
			tokens = tokens->next;
		while (tokens && tokens->type[0] != ' ' && tokens->type[0] != '\t'
			&& tokens->type[0] != '|')
			tokens = tokens->next;
	}
	return (count);
}

char	**make_words(t_tok *tokens, bool **word_is_quoted_arr)
{
	char	**res;
	bool	*quoted_flags;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * 20);
	quoted_flags = malloc(sizeof(bool) * 20);
	if (!res || !quoted_flags)
		return (NULL);
	while (tokens && tokens->type[0] != '|')
	{
		while (tokens && (tokens->type[0] == ' ' || tokens->type[0] == '\t'))
			tokens = tokens->next;
		if (!tokens || tokens->type[0] == '|')
			break ;
		quoted_flags[i] = false;
		if (tokens->type[0] == '>' || tokens->type[0] == '<')
			tokens = special_word(tokens, res + i);
		else
			tokens = l_words(tokens, res + i, &quoted_flags[i]);
		i++;
	}
	res[i] = NULL;
	*word_is_quoted_arr = quoted_flags;
	return (res);
}
