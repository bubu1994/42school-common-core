/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:55:47 by syslive           #+#    #+#             */
/*   Updated: 2024/09/25 11:10:34 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_exit_status(t_data *data, t_tok *prem_d)
{
	t_tok	*status_tok;
	t_tok	*precedant;
	t_tok	*inter_point;

	status_tok = new_pid_tokens(data->exit_status);
	precedant = prem_d->prev;
	inter_point = prem_d->next;
	if (precedant)
		precedant->next = status_tok;
	else
		data->tokens = status_tok;
	status_tok->prev = precedant;
	while (status_tok->next)
		status_tok = status_tok->next;
	status_tok->next = prem_d;
	prem_d->prev = status_tok;
	delete_elem(&data->tokens, prem_d);
	delete_elem(&data->tokens, inter_point);
}
