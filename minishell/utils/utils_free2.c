/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:09:24 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:09:24 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	double_free(char *s1, char *s2)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
}

void	print_tab_int(int *tabl)
{
	int	i;

	i = 0;
	while (tabl[i])
	{
		printf("%d) %i:\n", i + 1, tabl[i]);
		i++;
	}
}

void	free_main(t_data *data)
{
	g_ext_sig = 0;
	if (data->input != NULL && data->input[0])
		add_history(data->input);
	free_list_cmd(data->cmds);
	data->cmds = NULL;
	free_list_tok(data->tokens);
	data->tokens = NULL;
	if (data->input)
		free(data->input);
}
