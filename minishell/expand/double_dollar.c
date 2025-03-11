/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_dollars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 08:22:39 by marvin            #+#    #+#             */
/*   Updated: 2024/08/17 08:22:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_new_tok_pid(t_tok **list, char n)
{
	t_tok	*new;
	t_tok	*tmp;

	new = malloc(sizeof(t_tok));
	if (!new)
		return ;
	new->value = n;
	new->type = malloc(2);
	if (!new->type)
		return ;
	new->type[0] = 'l';
	new->type[1] = '\0';
	new->prev = NULL;
	new->next = NULL;
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

t_tok	*new_pid_tokens(int n)
{
	t_tok	*new_list;
	char	*str_pid;
	int		i;

	new_list = NULL;
	str_pid = ft_itoa(n);
	i = 0;
	while (str_pid[i])
	{
		add_new_tok_pid(&new_list, str_pid[i]);
		i++;
	}
	free(str_pid);
	return (new_list);
}

/*
void	expand_double_dollars(t_data *data, t_tok *prem_d)
{
	t_tok	*pid_toks;
	t_tok	*precedant;
	t_tok	*second_d;

	pid_toks = new_pid_tokens(data->pid);
	precedant = prem_d->prev;
	second_d = prem_d->next;
	if (precedant)
		precedant->next = pid_toks;
	else
		data->tokens = pid_toks;
	pid_toks->prev = precedant;
	while (pid_toks->next)
		pid_toks = pid_toks->next;
	pid_toks->next = prem_d;
	prem_d->prev = pid_toks;
	delete_elem(&data->tokens, prem_d);
	delete_elem(&data->tokens, second_d);
}*/
