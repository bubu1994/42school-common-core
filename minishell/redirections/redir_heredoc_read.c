/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc_read.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:22:43 by sforster          #+#    #+#             */
/*   Updated: 2024/09/30 11:16:45 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_heredoc(t_data *data, int fd[4])
{
	signal(SIGQUIT, SIG_IGN);
	sign_handler(2);
	dup2(fd[1], STDOUT_FILENO);
	dup2(data->saved_stdin, STDIN_FILENO);
	chdir("obj/redirections");
}

bool	read_heredoc(int fdh, char *oldpwd, char *delimiter)
{
	char	*new_line;

	while (1)
	{
		new_line = readline("heredoc> ");
		if (new_line == NULL)
		{
			if (g_ext_sig == SIGINT)
				return (heredoc_ctrl_c(fdh, oldpwd, new_line));
			else
			{
				ft_putstr_fd("warning: here-document delimited by EOF", 2);
				ft_putstr_fd(" (wanted \'", 2);
				putstr_stderr(delimiter, "\')\n");
				return (true);
			}
		}
		if (!ft_strcmp(new_line, delimiter))
			break ;
		ft_putstr_fd(new_line, fdh);
		ft_putchar_fd('\n', fdh);
		free(new_line);
	}
	return (true);
}

bool	redir_heredoc(t_cmd *cmd, t_word *word, t_data *data, int fd[4])
{
	int			fdh;
	char		oldpwd[PATH_MAX];

	getcwd(oldpwd, sizeof(oldpwd));
	init_heredoc(data, fd);
	fdh = open(".redir_main", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (read_heredoc(fdh, oldpwd, word->next->str) == false)
	{
		data->exit_status = 130;
		return (false);
	}
	close(fdh);
	sign_handler(1);
	if (cmd->next && cmd->simple_cmd)
		dup2(fd[3], STDOUT_FILENO);
	if (word->next->symb != QUOTED_DELIMITER)
		expand_heredoc(data);
	fdh = open(".redir_main", O_RDONLY);
	dup2(fdh, STDIN_FILENO);
	close(fdh);
	chdir(oldpwd);
	return (true);
}

bool	heredoc_ctrl_c(int fdh, char *oldpwd, char *new_line)
{
	g_ext_sig = 0;
	close(fdh);
	chdir(oldpwd);
	unlink_heredoc();
	if (new_line)
		free(new_line);
	return (false);
}
