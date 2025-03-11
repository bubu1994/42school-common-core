/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:03:00 by sforster          #+#    #+#             */
/*   Updated: 2024/09/24 20:31:29 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(char **input, t_data *data)
{
	char	*pwd;

	(void) input;
	pwd = get_pwd(data);
	printf("%s\n", pwd);
	free (pwd);
	data->exit_status = 0;
}
