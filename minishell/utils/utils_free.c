/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:09:15 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:09:15 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_data(t_data *data)
{
	close(data->saved_stdin);
	free(data->input);
	free_list_tok(data->tokens);
	free_list_env(data->env);
	free_list_env(data->tmp_env);
	if (data->env_tab)
		free_tab(data->env_tab);
	free_list_cmd(data->cmds);
	free(data);
}

void	free_list_env(t_env *lst)
{
	t_env	*temp;

	if (lst == NULL)
		return ;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp->env);
		if (temp->cont)
			free(temp->cont);
		free(temp);
	}
}

void	free_list_tok(t_tok *lst)
{
	t_tok	*temp;

	if (lst == NULL)
		return ;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp->type);
		free(temp);
	}
}

void	free_words(t_word *word)
{
	t_word	*temp;

	while (word)
	{
		temp = word;
		word = word->next;
		free(temp->str);
		free(temp);
	}
}

void	free_list_cmd(t_cmd *lst)
{
	t_cmd	*temp;

	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free_words(temp->words);
		free(temp->phrase);
		if (temp->simple_cmd)
			free(temp->simple_cmd);
		free(temp);
	}
}
