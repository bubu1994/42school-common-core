/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:32:07 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/12/27 13:47:45 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*join_char(char *chaine, char c)
{
	char	*str;
	int		i;

	if (!chaine)
	{
		chaine = malloc(1);
		if (!chaine)
			return (NULL);
		chaine[0] = '\0';
	}
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(chaine)) + 2);
	if (!str)
		return (NULL);
	while (chaine[i])
	{
		str[i] = chaine[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(chaine);
	return (str);
}

void	get_msg(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static int	bits;
	static char	*str;

	(void) context;
	if (sig == SIGUSR2)
		i = i | 1;
	bits++;
	if (bits == 8)
	{
		if (i == 0)
		{
			ft_printf("%s\n", str);
			str = NULL;
			kill(info->si_pid, SIGUSR1);
		}
		str = join_char(str, i);
		i = 0;
		bits = 0;
	}
	i = i << 1;
}

int	main(void)
{
	int					pid;
	struct sigaction	my_action;

	pid = getpid();
	ft_printf("Hola senor, mi PID es: %d\n", pid);
	my_action.sa_sigaction = get_msg;
	sigemptyset(&my_action.sa_mask);
	my_action.sa_flags = SA_RESTART;
	while (1)
	{
		sigaction(SIGUSR2, &my_action, NULL);
		sigaction(SIGUSR1, &my_action, NULL);
		pause();
	}
	return (0);
}
