/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:11:50 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:11:50 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*init_data1(char **env, int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->input = NULL;
	data->exit_status = 0;
	data->tokens = NULL;
	data->env = env_list(env);
	data->tmp_env = NULL;
	data->env_tab = env_to_tab(data->env);
	data->cmds = NULL;
	data->n_child = 0;
	data->saved_stdin = dup(STDIN_FILENO);
	(void) argc;
	(void) argv;
	termios_main();
	return (data);
}
