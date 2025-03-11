/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add_variable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:04:12 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:04:12 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_variable(char **input, t_data *data)
{
	int		i;

	i = 1;
	while (input[i])
	{
		if (check_variable(input[i], data) == true)
		{
			if (ft_strchr(input[i], '=') != NULL)
			{
				ft_add_var_env(input[i], data);
				free_tab(data->env_tab);
				data->env_tab = env_to_tab(data->env);
			}
			else
				ft_add_var_tmp(input[i], data);
			data->exit_status = 0;
		}
		i++;
	}
	return ;
}

bool	check_variable(char *v, t_data *data)
{
	int	i;

	i = 0;
	if (ft_isalpha(v[i]) == 0 && v[i] != '_')
	{
		putstr_stderr(v, ": not a valid identifier\n");
		data->exit_status = 1;
		return (false);
	}
	i++;
	while (v[i])
	{
		if (v[i] == '=')
			break ;
		if (ft_isalnum(v[i]) == 0 && v[i] != '_')
		{
			putstr_stderr(v, ": not a valid identifier\n");
			data->exit_status = 1;
			return (false);
		}
		i++;
	}
	return (true);
}

void	ft_add_var_env(char *input, t_data *data)
{
	t_env	*current;
	t_env	*newvar;

	if (data->env == NULL)
		return ;
	newvar = add_new_env(input);
	check_tmp(data, newvar);
	current = data->env;
	while (current != NULL)
	{
		if (ft_strcmp(current->env, newvar->env) == 0)
		{
			if (current->cont)
				free (current->cont);
			current->cont = ft_strdup(newvar->cont);
			free_list_env(newvar);
			return ;
		}
		if (current->next == NULL)
			break ;
		current = current->next;
	}
	current->next = newvar;
}

t_env	*add_new_env(char *input)
{
	t_env	*newvar;
	int		i;
	int		t;

	i = 0;
	t = 0;
	newvar = malloc(sizeof(t_env));
	if (!newvar)
		return (NULL);
	while (input[i] != '=')
		i++;
	newvar->env = malloc((i + 1) * (sizeof(char)));
	if (!newvar->env)
		return (NULL);
	while (t < i)
	{
		newvar->env[t] = input[t];
		t++;
	}
	newvar->env[i] = '\0';
	i++;
	newvar->cont = ft_strdup(input + i);
	newvar->next = NULL;
	return (newvar);
}

void	ft_add_var_tmp(char *input, t_data *data)
{
	t_env	*newnode;
	t_env	*current;

	if (data->tmp_env == NULL)
	{
		newnode = new_node_exp(input);
		data->tmp_env = newnode;
		return ;
	}
	current = data->tmp_env;
	while (current != NULL)
	{
		if (ft_strcmp(current->env, input) == 0)
			return ;
		if (current->next == NULL)
			break ;
		current = current->next;
	}
	newnode = new_node_exp(input);
	current->next = newnode;
}
