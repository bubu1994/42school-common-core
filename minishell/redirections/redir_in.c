/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:45:59 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/10/07 15:17:29 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_cmd_to_null(t_cmd *cmd, t_data *data)
{
	data->exit_status = 1;
	free(cmd->simple_cmd);
	cmd->simple_cmd = NULL;
}

bool	redir_in(t_word *word, t_cmd *cmd, t_data *data)
{
	int			fd;
	struct stat	path_stat;

	if (access(word->next->str, F_OK) == -1)
	{
		putstr_stderr(word->next->str, ": No such file or directory\n");
		set_cmd_to_null(cmd, data);
		return (false);
	}
	if (stat(word->next->str, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
	{
		putstr_stderr(word->next->str, ": Is a directory");
		set_cmd_to_null(cmd, data);
		return (false);
	}
	fd = open(word->next->str, O_RDONLY);
	if (fd == -1)
	{
		putstr_stderr(word->next->str, ": error opening file\n");
		set_cmd_to_null(cmd, data);
		return (false);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (true);
}
