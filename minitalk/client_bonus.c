/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:31:44 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/12/27 13:14:33 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

void	send_char(int pid, char c)
{
	int	shift;

	shift = 0;
	while (shift < 8)
	{
		if ((c << shift) & 128)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		shift++;
		usleep(100);
	}
}

void	confirm_msg(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Mensaje recibido.\n");
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid_target;

	if (argc != 3)
	{
		ft_printf("Por favor introduce argumentos válidos.\n");
		return (0);
	}
	i = 0;
	signal(SIGUSR1, confirm_msg);
	pid_target = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_char(pid_target, argv[2][i]);
		i++;
	}
	send_char(pid_target, '\0');
	return (0);
}
