/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:21:18 by syslive           #+#    #+#             */
/*   Updated: 2024/09/30 09:42:16 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **input, t_data *data)
{
	data->exit_status = 0;
	if (input[0] == NULL)
		ft_cd_base(data);
	else if (input[1] != NULL)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		data->exit_status = 1;
		return ;
	}
	else if (input[0][0] == '.' && input[0][1] == 0)
		return ;
	else if (input[0][0] == '.' && input[0][1] == '.' && input[0][2] == 0)
		ft_close_dir(data);
	else if (input[0][0] == '-' && input[0][1] == 0)
		ft_previous_dir(data);
	else if (ft_check_access_folder(input[0], data) == true)
	{
		if (input[0][0] == '/')
			ft_absolute_path(input[0], data);
		else
			ft_relative_path(input[0], data);
	}
}

bool	ft_check_access_folder(char *path, t_data *data)
{
	if (access(path, R_OK) != 0)
	{
		ft_putstr_fd("cd: ", 2);
		putstr_stderr(path, ": no such file or directory\n");
		data->exit_status = 1;
		return (false);
	}
	return (true);
}
