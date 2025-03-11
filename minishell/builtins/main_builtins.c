/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:05:31 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:05:31 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin(t_cmd *cmd, char **tab, t_data *data)
{
	if (ft_strcmp(tab[0], "exit"))
		data->exit_status = 0;
	if (!ft_strcmp(tab[0], "echo"))
		ft_echo(tab, data);
	else if (!ft_strcmp(tab[0], "cd"))
		ft_cd(tab + 1, data);
	else if (!ft_strcmp(tab[0], "pwd"))
		ft_pwd(tab, data);
	else if (!ft_strcmp(tab[0], "export"))
		ft_export(tab, data);
	else if (!ft_strcmp(tab[0], "unset"))
		ft_unset(tab, data);
	else if (!ft_strcmp(tab[0], "env"))
		ft_env(tab, data);
	else if (!ft_strcmp(tab[0], "exit"))
		ft_exit(cmd, data);
}

void	exec_builtin_in_child(t_cmd *cmd, char **tab, t_data *data)
{
	pid_t	pid;
	int		exit_st;

	pid = fork();
	data->child_pids[data->n_child] = pid;
	data->n_child++;
	if (pid == -1)
		error_exit("fork");
	if (pid == 0)
	{
		exec_builtin(cmd, tab, data);
		exit_st = data->exit_status;
		free_data(data);
		exit(exit_st);
	}
}

char	**tabl_builtins(void)
{
	char	**blts;

	blts = malloc(8 * sizeof(char *));
	if (!blts)
		return (false);
	blts[0] = ft_strdup("echo");
	blts[1] = ft_strdup("cd");
	blts[2] = ft_strdup("pwd");
	blts[3] = ft_strdup("export");
	blts[4] = ft_strdup("unset");
	blts[5] = ft_strdup("env");
	blts[6] = ft_strdup("exit");
	blts[7] = NULL;
	return (blts);
}

bool	is_builtin(char **tab)
{
	char	**blts;
	int		i;

	blts = tabl_builtins();
	i = 0;
	while (i <= 6)
	{
		if (!ft_strcmp(blts[i], tab[0]))
		{
			free_tab(blts);
			return (true);
		}
		i++;
	}
	free_tab(blts);
	return (false);
}
