/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:09:45 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/06/05 10:51:30 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_ext_sig;

void	exit_with_status(t_data *data)
{
	int	exit_status;

	exit_status = data->exit_status;
	printf("exit\n");
	free_data(data);
	exit(exit_status);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	data = init_data1(env, argc, argv);
	g_ext_sig = 0;
	while (1)
	{
		sign_handler(1);
		data->input = readline(RED "B" ORANGE "o" YELLOW "m" GREEN
				"b" BLUE "s" MAGENTA "h" CYAN "ell > " RESET);
		if (data->input == NULL)
			exit_with_status(data);
		if (data->input[0] != '\0' && parsing(data))
		{
			expand(data);
			data->cmds = build_cmds(data->tokens);
			execution(data->cmds, data);
			unlink_heredoc();
		}
		sign_handler(1);
		free_main(data);
	}
}
