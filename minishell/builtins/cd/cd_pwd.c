/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:21:23 by syslive           #+#    #+#             */
/*   Updated: 2024/09/30 09:33:13 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	newpwd_cd(char *path, t_data *data)
{
	t_env	*current;

	current = data->env;
	while (current->next)
	{
		if (ft_strcmp(current->env, "PWD") == 0)
		{
			free(current->cont);
			current->cont = path;
			free_tab(data->env_tab);
			data->env_tab = env_to_tab(data->env);
			return ;
		}
		current = current->next;
	}
	free(path);
	return ;
}

void	oldpwd_cd(t_data *data)
{
	t_env	*current;
	char	*actualpwd;

	current = data->env;
	actualpwd = get_pwd(data);
	while (current->next != NULL)
	{
		if (ft_strcmp(current->env, "OLDPWD") == 0)
		{
			free(current->cont);
			current->cont = actualpwd;
			return ;
		}
		current = current->next;
	}
	if (ft_strcmp(current->env, "OLDPWD") == 0)
	{
		free(current->cont);
		current->cont = actualpwd;
		return ;
	}
	free (actualpwd);
}

char	*get_pwd(t_data *data)
{
	char	*path;
	char	path2[PATH_MAX];

	(void) data;
	path = NULL;
	getcwd(path2, sizeof(path2));
	path = ft_strdup(path2);
	return (path);
}

char	*get_home(t_data *data)
{
	char	*path;
	t_env	*scan;

	path = NULL;
	scan = data->env;
	while (scan)
	{
		if (ft_strcmp(scan->env, "HOME") == 0)
		{
			path = ft_strdup(scan->cont);
			break ;
		}
		scan = scan->next;
	}
	return (path);
}
