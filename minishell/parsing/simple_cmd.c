/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>              +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:18:07 by gebuqaj               #+#    #+#         */
/*   Updated: 2024/09/23 23:05:26 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	res_size(t_word *word)
{
	int		i;
	t_word	*scan;

	i = 0;
	scan = word;
	while (scan)
	{
		if (scan->symb == LIT || scan->symb == QUOTED)
			i++;
		scan = scan->next;
	}
	return (i);
}

char	**the_command(t_word *words)
{
	char	**res;
	t_word	*scan;
	int		i;

	scan = words;
	i = res_size(words);
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	scan = words;
	while (scan)
	{
		if (scan->symb == LIT || scan->symb == QUOTED)
			res[i++] = scan->str;
		scan = scan->next;
	}
	res[i] = NULL;
	return (res);
}
