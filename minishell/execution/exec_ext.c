/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:14:08 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/06/05 10:56:13 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_path_slash_input(char *path_rep, char *input)
{
	char	*res;
	char	*rep_slash;

	rep_slash = ft_strjoin(path_rep, "/");
	res = ft_strjoin(rep_slash, input);
	free(rep_slash);
	return (res);
}

char	*get_path(t_data *data)
{
	char	*res;
	t_env	*scan;

	res = NULL;
	scan = data->env;
	while (scan)
	{
		if (!ft_strcmp("PATH", scan->env))
		{
			res = scan->cont;
			break ;
		}
		scan = scan->next;
	}
	return (res);
}

int	is_extern(char **input, t_data *data)
{
	char	**path_tab;
	char	*path_to_exec;
	char	*path;
	int		i;

	if (!input[0][0])
		return (0);
	path = get_path(data);
	if (!path)
		return (0);
	path_tab = ft_split(path, ':');
	i = -1;
	while (path_tab[++i])
	{
		path_to_exec = join_path_slash_input(path_tab[i], input[0]);
		if (access(path_to_exec, X_OK) == 0)
		{
			free(path_to_exec);
			free_tab(path_tab);
			return (1);
		}
		free(path_to_exec);
	}
	free_tab(path_tab);
	return (0);
}

void	exec_extern(char **input, int fd[4], t_data *data)
{
	char	**path_tab;
	char	*path_to_exec;
	char	*path;
	int		i;

	path = get_path(data);
	path_tab = ft_split(path, ':');
	i = -1;
	while (path_tab[++i])
	{
		path_to_exec = join_path_slash_input(path_tab[i], input[0]);
		if (access(path_to_exec, X_OK) == 0)
		{	
			close(fd[1]);
			close(fd[2]);
			close(fd[3]);
			close(data->saved_stdin);
			execve(path_to_exec, input, data->env_tab);
			putstr_stderr(path_to_exec, ": erreur execve\n");
		}
	}
	data->exit_status = 127;
	printf("Erreur exec_extern\n");
}

void	fork_extern_command(char **input, t_data *data, int fd[4])
{
	pid_t	pid_child;

	pid_child = fork();
	data->child_pids[data->n_child] = pid_child;
	data->n_child++;
	if (pid_child < 0)
		error_exit("fork");
	if (pid_child == 0)
	{
		exec_extern(input, fd, data);
	}
}
