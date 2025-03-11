/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:16:55 by syslive           #+#    #+#             */
/*   Updated: 2024/09/24 20:35:13 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **input, t_data *data)
{
	if (!data->env)
	{
		data->exit_status = 125;
	}
	print_list_env(data->env);
	(void) input;
	data->exit_status = 0;
}
