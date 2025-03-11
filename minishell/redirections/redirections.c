/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:08:14 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:08:14 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	redir_out(t_word *word, t_cmd *cmd, t_data *data)
{
	int			fd;
	struct stat	path_stat;

	if (stat(word->next->str, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
	{
		putstr_stderr(word->next->str, ": Is a directory\n");
		data->exit_status = 1;
		free(cmd->simple_cmd);
		cmd->simple_cmd = NULL;
		return (false);
	}
	fd = open(word->next->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		putstr_stderr(word->next->str, ": error opening file\n");
		data->exit_status = 1;
		free(cmd->simple_cmd);
		cmd->simple_cmd = NULL;
		return (false);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (true);
}

bool	redir_out_append(t_word *word, t_cmd *cmd, t_data *data)
{
	int			fd;
	struct stat	path_stat;

	if (stat(word->next->str, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
	{
		putstr_stderr(word->next->str, ": Is a directory\n");
		data->exit_status = 1;
		free(cmd->simple_cmd);
		cmd->simple_cmd = NULL;
		return (false);
	}
	fd = open(word->next->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		putstr_stderr(word->next->str, ": error opening file\n");
		data->exit_status = 1;
		free(cmd->simple_cmd);
		cmd->simple_cmd = NULL;
		return (false);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (true);
}

bool	stop_redir(t_cmd *cmd, t_data *data, t_word *scan)
{
	if (scan->symb == 1)
	{
		if (redir_out(scan, cmd, data) == false)
			return (true);
	}
	else if (scan->symb == 2)
	{
		if (redir_out_append(scan, cmd, data) == false)
			return (true);
	}
	else if (scan->symb == 3)
	{
		if (redir_in(scan, cmd, data) == false)
			return (true);
	}
	return (false);
}

bool	redirections(t_cmd *cmd, t_data *data, int fd[4])
{
	t_word	*scan;

	scan = cmd->words;
	while (scan)
	{
		if (scan->symb == 4)
		{		
			if (redir_heredoc(cmd, scan, data, fd) == false)
				return (false);
		}
		if (stop_redir(cmd, data, scan) == true)
			return (true);
		scan = scan->next;
	}
	return (true);
}

/* bool	redirections(t_cmd *cmd, t_data *data, int fd[4])
{
	t_word	*scan;

	scan = cmd->words;
	while (scan)
	{
		if (scan->symb == 4)
		{		
			if (redir_heredoc(cmd, scan, data, fd) == false)
				return (false);
		}
		else if (scan->symb == 1)
		{
			if (redir_out(scan, cmd, data) == false)
				return (true);
		}
		else if (scan->symb == 2)
		{
			if (redir_out_append(scan, cmd, data) == false)
				return (true);
		}
		else if (scan->symb == 3)
		{
			if (redir_in(scan, cmd, data) == false)
				return (true);
		}
		scan = scan->next;
	}
	return (true);
} */
