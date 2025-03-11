/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:13:14 by sforster          #+#    #+#             */
/*   Updated: 2024/09/29 23:07:45 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	termios_main(void)
{
	static struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &term);
}

/*
void	reset_terminal_mode(struct termios *orig_termios, int saved_stdin)
{
	tcsetattr(saved_stdin, TCSANOW, orig_termios);
}

struct termios	*set_custom_mode(struct termios *orig_termios)
{
	struct termios	*new_termios;

	orig_termios = malloc(sizeof(struct termios));
	tcgetattr(STDIN_FILENO, orig_termios);
	new_termios = orig_termios;
	new_termios->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, new_termios);
	return (new_termios);
}

void	termios_main(t_data *data)
{
	struct termios	*origin_termios;
	struct termios	*new_termios;

	origin_termios = NULL;
	new_termios = set_custom_mode(origin_termios);
	data->new_termios = new_termios;
	data->origin_termios = origin_termios;
}
*/

/*
void	reset_terminal_mode(struct termios *orig_termios, int saved_stdin)
{
	tcsetattr(saved_stdin, TCSANOW, orig_termios);
	free(orig_termios);
	orig_termios = NULL;
}


struct termios	*set_custom_mode(struct termios *orig_termios)
{
	struct termios	*new_termios;

	new_termios = orig_termios;
	new_termios->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, new_termios);
	return (new_termios);
}

void	termios_main(t_data *data)
{
	struct termios	*origin_termios;
	struct termios	*new_termios;

	origin_termios = malloc(sizeof(struct termios));
	tcgetattr(STDIN_FILENO, origin_termios);
	new_termios = malloc(sizeof(struct termios));
	tcgetattr(STDIN_FILENO, origin_termios);
	new_termios->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, new_termios);

	data->new_termios = new_termios;
	data->origin_termios = origin_termios;
}
*/