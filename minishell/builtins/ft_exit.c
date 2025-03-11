/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:34:33 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/10/08 13:50:24 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_numeric(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '\0')
		return (0);
	if (num[0] == '-' || num[0] == '+')
		i = 1;
	while (num[i])
	{
		if (!isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_cmd *cmd, t_data *data)
{
	int	exit_arg;

	if (cmd->next || cmd->prev)
		return ;
	if (cmd->simple_cmd[1] && cmd->simple_cmd[2])
	{
		putstr_stderr(cmd->simple_cmd[0], ": too many arguments\n");
		data->exit_status = 1;
	}
	else if (cmd->simple_cmd[1])
	{
		if (is_numeric(cmd->simple_cmd[1]))
			data->exit_status = ft_atoi(cmd->simple_cmd[1]);
		else
		{
			ft_putstr_fd("exit\n", 2);
			putstr_stderr(cmd->simple_cmd[1], ": numeric argument required\n");
			data->exit_status = 2;
		}
	}
	exit_arg = data->exit_status;
	free_data(data);
	exit(exit_arg);
}
