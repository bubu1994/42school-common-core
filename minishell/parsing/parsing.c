/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:53:40 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/09/24 09:00:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	last_elem_is_pipe(t_tok *tokens)
{
	while (tokens->next)
		tokens = tokens->next;
	while (tokens->prev && tokens->value == ' ')
		tokens = tokens->prev;
	if (tokens->type[0] == '|')
		return (1);
	return (0);
}

char	*get_next_input(char *input, t_data *data)
{
	char	*full_input;
	char	*next_input;

	sign_handler(3);
	next_input = NULL;
	write(1, "> ", 2);
	while (1)
	{
		next_input = read_next_input(input, data);
		if (next_input == NULL)
			return (NULL);
		if (next_input[0] != '\0')
			break ;
		free(next_input);
	}
	full_input = ft_strjoin(input, next_input);
	double_free(next_input, input);
	return (full_input);
}

int	quote_and_syntax(t_data *data)
{
	if (!quoting(data->tokens))
	{
		ft_putstr_fd("error quoting\n", 2);
		data->exit_status = 2;
		return (0);
	}
	if (!syntax_ok(data->tokens))
	{
		ft_putstr_fd("error syntax\n", 2);
		data->exit_status = 2;
		return (0);
	}
	return (1);
}

int	parsing(t_data *data)
{
	if (ft_strlen(data->input) > 2000000)
	{
		ft_putstr_fd("minishell: too big input\n", 2);
		return (0);
	}
	if (data->tokens)
		free_list_tok(data->tokens);
	data->tokens = tokenise(data->input);
	if (!quote_and_syntax(data))
		return (0);
	if (last_elem_is_pipe(data->tokens))
	{
		data->input = get_next_input(data->input, data);
		sign_handler(1);
		if (data->input == NULL)
		{
			data->exit_status = 130;
			return (0);
		}
		if (!parsing(data))
			return (0);
	}
	return (1);
}
