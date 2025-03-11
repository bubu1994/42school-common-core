/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:09:48 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:09:48 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tabl)
{
	int	i;

	if (tabl == NULL)
	{
		return ;
	}
	i = -1;
	while (tabl[++i])
		free(tabl[i]);
	free(tabl);
}

int	nb_of_elem(char **tabl)
{
	int	i;

	i = 0;
	while (tabl[i])
		i++;
	return (i);
}
