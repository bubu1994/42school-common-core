/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:57:08 by sforster          #+#    #+#             */
/*   Updated: 2024/09/24 20:36:18 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cd
void	ft_cd_base(t_data *data)
{
	char	*home_path;

	home_path = get_home(data);
	if (home_path == NULL)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		data->exit_status = 1;
		return ;
	}
	oldpwd_cd(data);
	chdir(home_path);
	newpwd_cd(home_path, data);
	data->exit_status = 0;
	return ;
}

char	*path_back(char *path, char *new_path)
{
	int		i;
	int		t;

	i = 0;
	t = 0;
	while (path[i])
	{
		if (path[i] == '/' && path[i + 1] && path[i + 2]
			&& path[i + 1] == '.' && path[i + 2] == '.')
		{
			i += 3;
			if (t > 0)
				t -= 1;
			while (new_path[t] != '/' && t >= 0)
				t--;
		}
		else
			new_path[t++] = path[i++];
	}
	if (t == 0)
		new_path[t++] = '/';
	new_path[t] = '\0';
	return (new_path);
}

char	*path_close_dir(char *actualpath)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	path = malloc(PATH_MAX * sizeof(char));
	if (!path)
		return (NULL);
	j = ft_strlen(actualpath);
	while (actualpath[j] != '/')
		j--;
	while (i < j)
	{
		path[i] = actualpath[i];
		i++;
	}
	if (i == 0)
	{
		path[i] = '/';
		i++;
	}
	path[i] = '\0';
	return (path);
}

// cd ..
void	ft_close_dir(t_data *data)
{
	char	*path;
	char	*actualpath;

	actualpath = get_pwd(data);
	oldpwd_cd(data);
	path = path_close_dir(actualpath);
	free(actualpath);
	chdir(path);
	data->exit_status = 0;
	newpwd_cd(path, data);
	return ;
}

// cd -
void	ft_previous_dir(t_data *data)
{
	char	*path;
	t_env	*current;

	current = data->env;
	while (current->next != NULL && ft_strcmp(current->env, "OLDPWD") != 0)
	{
		current = current->next;
	}
	if (strcmp(current->env, "OLDPWD") != 0)
	{
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
		data->exit_status = 1;
		return ;
	}
	path = ft_strdup(current->cont);
	oldpwd_cd(data);
	chdir(path);
	printf("%s\n", path);
	newpwd_cd(path, data);
	data->exit_status = 0;
	return ;
}
