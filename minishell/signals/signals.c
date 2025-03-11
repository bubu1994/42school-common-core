/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:40:11 by sforster          #+#    #+#             */
/*   Updated: 2024/09/30 10:21:55 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sig_heredoc(int sig)
{
	ft_printf("\n");
	g_ext_sig = sig;
	close(STDIN_FILENO);
}

void	sign_handler(int shell_stat)
{
	struct sigaction	sa;
	sigset_t			set;

	ft_memset(&sa, 0, sizeof(sa));
	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sa.sa_mask = set;
	if (shell_stat == 1)
		sa.sa_handler = handle_sig_main;
	else if (shell_stat == 2)
		sa.sa_handler = handle_sig_heredoc;
	else if (shell_stat == 3)
		sa.sa_handler = handle_sig_next_pipe;
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	handle_sig_main(int sig)
{
	ft_relauch();
	(void) sig;
}

void	handle_sig_next_pipe(int sig)
{
	printf("^C");
	printf("\n");
	g_ext_sig = sig;
}

void	ft_relauch(void)
{
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	return ;
}
