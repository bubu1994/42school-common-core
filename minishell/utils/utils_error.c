/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:09:04 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:09:04 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_exit(char *error_message)
{
	printf("Erreur: %s\n", error_message);
	exit(1);
}

void	putstr_stderr(char *word, char *error_msg)
{
	ft_putstr_fd(word, 2);
	ft_putstr_fd(error_msg, 2);
}
