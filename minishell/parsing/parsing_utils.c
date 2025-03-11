/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 23:05:27 by sforster          #+#    #+#             */
/*   Updated: 2024/09/29 23:07:06 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_d_next_pipe(char *input, char *next_input, t_data *data)
{
	ft_putstr_fd("syntax error: unexpected end of file\n", 2);
	(void) input;
	free(next_input);
	printf("exit\n");
	free_data(data);
	exit(2);
}

char	*read_next_input(char *input, t_data *data)
{
	char	*next_input;
	char	tmp;

	next_input = NULL;
	while (read(0, &tmp, 1))
	{
		if (g_ext_sig == SIGINT)
		{
			double_free(input, next_input);
			return (NULL);
		}
		else if (tmp != '\n')
			next_input = ft_strjoin_char(next_input, tmp);
		else if (next_input == NULL && tmp == '\n')
			write(1, "> ", 2);
		else if (next_input != NULL && tmp == '\n')
			break ;
	}
	if (next_input == NULL)
		ctrl_d_next_pipe(input, next_input, data);
	return (next_input);
}
