/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 01:09:25 by marvin            #+#    #+#             */
/*   Updated: 2024/08/26 01:09:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	assign_symb(char *word, bool word_is_quoted)
{
	int	res;

	if (!ft_strcmp(word, ">"))
		res = SUP;
	else if (!ft_strcmp(word, ">>"))
		res = SUP_SUP;
	else if (!ft_strcmp(word, "<"))
		res = INF;
	else if (!ft_strcmp(word, "<<"))
		res = INF_INF;
	else if (word_is_quoted)
		res = QUOTED;
	else
		res = LIT;
	return (res);
}

void	add_new_word(t_word **list, char *word, int i, bool word_is_quoted)
{
	t_word	*new;
	t_word	*tmp;

	new = malloc(sizeof(t_word));
	if (!new)
		return ;
	new->str = ft_strdup(word);
	new->pos = i;
	new->symb = assign_symb(word, word_is_quoted);
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

t_word	*build_words(t_tok *token)
{
	t_word	*list;
	char	**words;
	int		i;
	bool	*word_is_quoted_arr;

	i = 0;
	list = NULL;
	words = make_words(token, &word_is_quoted_arr);
	while (words[i])
	{
		add_new_word(&list, words[i], i, word_is_quoted_arr[i]);
		i++;
	}
	free_tab(words);
	free(word_is_quoted_arr);
	words = NULL;
	return (list);
}
