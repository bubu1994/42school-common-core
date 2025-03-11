/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:09:33 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:09:33 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tab(char **tabl)
{
	int	i;

	i = 0;
	while (tabl[i] != NULL)
	{
		if (tabl[i][0] == '\0')
			printf("1er char null ");
		printf("%d) %s:\n", i + 1, tabl[i]);
		i++;
	}
}

void	print_list(t_cmd *list)
{
	t_cmd	*scan;
	int		i;

	i = 1;
	scan = list;
	while (scan)
	{
		printf("%d) %s\n", i++, scan->phrase);
		scan = scan->next;
	}
}

void	print_list_env(t_env *list)
{
	while (list)
	{
		printf("%s=%s\n", list->env, list->cont);
		list = list->next;
	}
}

void	print_list_tokens(t_tok *list)
{
	if (list == NULL)
	{
		printf("vide \n");
		return ;
	}
	while (list)
	{
		printf("value: %c, type: %s:\n", list->value, list->type);
		list = list->next;
	}
}

/*
void	print_list_commandes(t_cmd *list)
{
	t_cmd	*scan;
	t_word	*word_scan;
	int		i;

	i = 0;
	scan = list;
	if (scan == NULL)
	{
		printf("vide \n");
		return ;
	}
	while (scan)
	{
		printf("commande complète: %s.\n", scan->phrase);
		word_scan = scan->words;
		while (word_scan)
		{
			printf("mot:%s (%d)\n", word_scan->str, word_scan->symb);
			word_scan = word_scan->next;
		}
		printf("command simple:");
		while (scan->simple_cmd[i])
			printf(" %s,", scan->simple_cmd[i++]);
		printf("\n");
		scan = scan->next;
	}
}*/
