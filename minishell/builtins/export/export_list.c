/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:04:30 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:04:30 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_list(t_data *data)
{
	t_env	*lst_export;

	lst_export = NULL;
	if (data->env != NULL)
		order_var_env(&lst_export, data->env);
	if (data->tmp_env != NULL && data->env != NULL)
		order_var_env_var_tmp(&lst_export, data->tmp_env);
	print_export(lst_export);
	free_list_env(lst_export);
	data->exit_status = 0;
}

void	order_var_env(t_env **new_list, t_env *env)
{
	t_env	*current_env;
	t_env	*current_list;
	t_env	*new_node;

	*new_list = new_env(env);
	current_env = env->next;
	while (current_env)
	{
		current_list = *new_list;
		new_node = new_env(current_env);
		if (ft_strcmp(new_node->env, (*new_list)->env) < 0)
		{
			new_node->next = *new_list;
			*new_list = new_node;
		}
		else
		{
			while (current_list->next != NULL
				&& ft_strcmp(new_node->env, current_list->next->env) > 0)
				current_list = current_list->next;
			new_node->next = current_list->next;
			current_list->next = new_node;
		}
		current_env = current_env->next;
	}
}

void	order_var_env_var_tmp(t_env **new_list, t_env *env)
{
	t_env	*current_env;
	t_env	*c_list;
	t_env	*new_node;

	current_env = env;
	while (current_env)
	{
		c_list = *new_list;
		new_node = new_env(current_env);
		if (ft_strcmp(new_node->env, (*new_list)->env) < 0)
		{
			new_node->next = *new_list;
			*new_list = new_node;
		}
		else
		{
			while (c_list->next != NULL
				&& ft_strcmp(new_node->env, c_list->next->env) > 0)
				c_list = c_list->next;
			new_node->next = c_list->next;
			c_list->next = new_node;
		}
		current_env = current_env->next;
	}
}

void	print_export(t_env *list)
{
	while (list)
	{
		printf("export %s", list->env);
		if (list->cont != NULL)
			printf("=%c%s%c", 34, list->cont, 34);
		printf("\n");
		list = list->next;
	}
}
