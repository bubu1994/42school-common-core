/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:05:43 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:05:43 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char **input, t_data *data)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (data->tmp_env != NULL)
			unset_el(&data->tmp_env, input[i]);
		if (data->env != NULL)
			unset_el(&data->env, input[i]);
		i++;
	}
	free_tab(data->env_tab);
	data->env_tab = env_to_tab(data->env);
	data->exit_status = 0;
}

void	unset_el(t_env **list, char *name)
{
	t_env	*current;
	t_env	*tmp;

	current = *list;
	if (ft_strcmp(current->env, name) == 0)
	{
		*list = current->next;
		free_env(current);
		return ;
	}
	while (current->next)
	{
		if (ft_strcmp(current->next->env, name) == 0)
		{
			tmp = current->next;
			if (current->next->next)
				current->next = current->next->next;
			else
				current->next = NULL;
			free_env(tmp);
		}
		if (current->next == NULL)
			break ;
		current = current->next;
	}
}

void	free_env(t_env *env)
{
	env->next = NULL;
	free (env->env);
	free (env->cont);
	free (env);
}
