/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:07:10 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:07:10 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_env_name(t_data *data, t_tok *prem_d)
{
	char	*name;
	t_tok	*end_name;
	t_tok	*tmp;

	name = NULL;
	end_name = prem_d->next;
	name = malloc(2 * sizeof(char));
	name[0] = end_name->value;
	name[1] = '\0';
	while (1)
	{
		if (end_name->next == NULL
			|| !ft_isalnum(end_name->next->value)
			|| *end_name->next->type != 'l')
			break ;
		tmp = end_name;
		end_name = end_name->next;
		delete_elem(&data->tokens, tmp);
		name = ft_strjoin_char(name, end_name->value);
	}
	delete_elem(&data->tokens, end_name);
	return (name);
}

void	expand_var_env(t_data *data, t_tok *prem_d, char s)
{
	char	*name;
	t_tok	*new_tok;

	new_tok = NULL;
	if (prem_d->next->value == ' ')
		return ;
	name = extract_env_name(data, prem_d);
	new_tok = new_env_tok(data->env, name, s);
	if (new_tok)
		insert_new_tok(prem_d, new_tok);
	free (name);
	delete_elem(&data->tokens, prem_d);
}
