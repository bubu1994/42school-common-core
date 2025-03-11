/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_programm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:06:19 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:06:19 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fork_programm(char **input, t_data *data, int fd[4])
{
	pid_t	pid_child;

	if (check_access_executable(input, data) == false)
		return ;
	pid_child = fork();
	data->child_pids[data->n_child] = pid_child;
	data->n_child++;
	if (pid_child < 0)
		error_exit("fork");
	if (pid_child == 0)
	{
		exec_programm(data, input, fd);
	}
}

void	exec_programm(t_data *data, char **input, int fd[4])
{
	if (input[0] == NULL)
		return ;
	close(data->saved_stdin);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	execve(input[0], input, data->env_tab);
}

bool	check_access_executable(char **input, t_data *data)
{
	struct stat	file_info;

	stat(input[0], &file_info);
	if (S_ISDIR(file_info.st_mode))
	{
		putstr_stderr(input[0], ": Is a directory \n");
		data->exit_status = 126;
		return (false);
	}
	else if (access(input[0], F_OK) != 0)
	{
		putstr_stderr(input[0], ": No such file or directory\n");
		data->exit_status = 127;
		return (false);
	}
	else if (access(input[0], X_OK) != 0)
	{
		putstr_stderr(input[0], ": Permission denied\n");
		data->exit_status = 126;
		return (false);
	}
	return (true);
}
