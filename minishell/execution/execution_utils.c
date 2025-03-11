/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:49:22 by sforster          #+#    #+#             */
/*   Updated: 2024/09/30 10:51:31 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	restore_and_kill(t_data *data, int fd[4])
{
	int	i;

	i = -1;
	dup2(data->saved_stdin, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	while (++i < data->n_child)
		kill(data->child_pids[i], SIGKILL);
}

void	dup_close(int fd[4])
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd[2], STDIN_FILENO);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
}

void	restore_close(t_data *data, int fd[4])
{
	dup2(data->saved_stdin, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
}
