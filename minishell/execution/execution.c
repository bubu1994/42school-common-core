/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:18:07 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/09/23 12:13:44 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	kill_processes(t_data *data)
{
	int	t;

	t = -1;
	printf("sig catched\n");
	while (++t < data->n_child)
		kill(data->child_pids[t], SIGKILL);
	g_ext_sig = 0;
}

void	waitpids_and_restore(t_data *data, int fd[4])
{
	int	i;
	int	status;

	i = -1;
	restore_close(data, fd);
	signal(SIGINT, SIG_IGN);
	while (++i < data->n_child)
	{
		if (g_ext_sig == SIGINT)
		{
			kill_processes(data);
			return ;
		}
		waitpid(data->child_pids[i], &status, 0);
		data->child_pids[i] = 0;
		sign_handler(1);
		if (WIFEXITED(status))
			data->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			data->exit_status = 130;
	}
	data->n_child = 0;
	restore_close(data, fd);
}

void	execution(t_cmd *list, t_data *data)
{
	int			fd[4];

	if (!list)
		return ;
	if (pipe(fd + 2) == -1)
		error_exit("pipe");
	fd[1] = dup(STDOUT_FILENO);
	if (list->simple_cmd && list->next)
		dup2(fd[3], STDOUT_FILENO);
	if (redirections(list, data, fd) != true)
	{
		restore_and_kill(data, fd);
		return ;
	}
	sign_handler(1);
	exe_command(list, list->simple_cmd, data, fd);
	if (list->next == NULL || data->n_child > 99)
	{
		if (data->n_child > 99)
			perror("Too many commands\n");
		waitpids_and_restore(data, fd);
		return ;
	}
	dup_close(fd);
	execution(list->next, data);
}
