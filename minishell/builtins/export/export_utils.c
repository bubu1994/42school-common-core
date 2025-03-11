/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:24:27 by sforster          #+#    #+#             */
/*   Updated: 2024/09/30 11:18:50 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_env(t_env	*env)
{
	t_env	*newnode;

	newnode = malloc(sizeof(t_env));
	if (!newnode)
	{
		return (NULL);
	}
	newnode->env = ft_strdup(env->env);
	if (env->cont)
		newnode->cont = ft_strdup(env->cont);
	else
		newnode->cont = NULL;
	newnode->next = NULL;
	return (newnode);
}

void	pushback_base(t_env **new_list, t_env *actual_node)
{
	t_env	*newnode;
	t_env	*current;

	current = *new_list;
	newnode = new_env(actual_node);
	if (*new_list == NULL)
	{
		*new_list = newnode;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = newnode;
}

void	check_tmp(t_data *data, t_env *newv)
{
	if (data->tmp_env != NULL)
		unset_el(&data->tmp_env, newv->env);
}

t_env	*new_node_exp(char *str)
{
	t_env	*newnode;

	newnode = malloc(sizeof(t_env));
	if (!newnode)
		return (NULL);
	newnode->env = ft_strdup(str);
	newnode->cont = NULL;
	newnode->next = NULL;
	return (newnode);
}
