/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:57:36 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/09/24 20:30:49 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **input, t_data *data)
{
	int	i;
	int	newline;

	if (!input[1])
	{
		write(1, "\n", 1);
		return ;
	}
	newline = 1;
	i = 1;
	if (!ft_strcmp(input[1], "-n") && input[1])
	{
		newline = 0;
		i = 2;
	}
	while (input[i])
	{
		write(1, input[i], ft_strlen(input[i]));
		if (input[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline)
		write(1, "\n", 1);
	data->exit_status = 0;
}
