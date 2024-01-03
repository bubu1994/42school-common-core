/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:32:13 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/12/27 13:26:49 by gebuqaj          ###   ########.fr       */
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

void	get_msg(int sig)
{
	static int	i;
	static int	bits;
	static char	*str;

	if (sig == SIGUSR2)
		i = i | 1;
	bits++;
	if (bits == 8)
	{
		if (i == 0)
		{
			ft_printf("%s\n", str);
			str = NULL;
		}
		str = join_char(str, i);
		i = 0;
		bits = 0;
	}
	i = i << 1;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Hola senor, mi PID es: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, get_msg);
		signal(SIGUSR2, get_msg);
		pause();
	}
	return (0);
}
