/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_absolute_relative.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:57:08 by sforster          #+#    #+#             */
/*   Updated: 2024/09/24 20:36:18 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cd /home/dir/dir
void	ft_absolute_path(char *path, t_data *data)
{
	char	*pathname;

	oldpwd_cd(data);
	chdir(path);
	data->exit_status = 0;
	pathname = ft_strdup(path);
	newpwd_cd(pathname, data);
	return ;
}

// cd dir/dir
void	ft_relative_path(char *path_folder, t_data *data)
{
	char	*path;
	char	*path2;
	char	*actualpath;
	int		i;

	oldpwd_cd(data);
	actualpath = get_pwd(data);
	path = ft_strjoin(actualpath, "/");
	free (actualpath);
	i = (ft_strlen(path_folder) - 1);
	if (path_folder[i] == '/')
		path_folder[i] = '\0';
	path2 = ft_strjoin(path, path_folder);
	free(path);
	chdir(path2);
	path = malloc(PATH_MAX * sizeof(char));
	if (!path)
		return ;
	path = path_back(path2, path);
	data->exit_status = 0;
	newpwd_cd(path, data);
	free (path2);
	return ;
}
