/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:04:42 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:04:42 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(char **input, t_data *data)
{
	if (input[1] == NULL)
		ft_export_list(data);
	else if (input[1] != NULL)
		ft_add_variable(input, data);
}
