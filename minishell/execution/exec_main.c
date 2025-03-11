/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:06:08 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:06:08 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	null_cmd(t_data *data)
{
	pid_t	pid;
	int		st;

	pid = fork();
	data->child_pids[data->n_child] = pid;
	data->n_child++;
	if (pid == 0)
	{
		st = data->exit_status;
		free_data(data);
		exit(st);
	}
}

void	exe_command(t_cmd *cmd, char **input, t_data *data, int fd[4])
{
	if (!input || !input[0])
	{
		null_cmd(data);
		return ;
	}
	if (!ft_strncmp(input[0], "./", 2) || !ft_strncmp(input[0], "../", 3)
		|| !ft_strncmp(input[0], "/", 1))
		fork_programm(input, data, fd);
	else if (is_builtin(input))
	{
		if (cmd->next || cmd->prev)
			exec_builtin_in_child(cmd, input, data);
		else
			exec_builtin(cmd, input, data);
	}
	else if (is_extern(input, data))
		fork_extern_command(input, data, fd);
	else
	{
		dup2(fd[1], STDOUT_FILENO);
		putstr_stderr(input[0], ": command not found\n");
		data->exit_status = 127;
	}
}
