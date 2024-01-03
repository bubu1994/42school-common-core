/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:31:58 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/03 13:57:02 by gebuqaj          ###   ########.fr       */
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

void	send_msg(int pid, char c)
{
	int	shift;

	shift = 0;
	while (shift < 8)
	{
		if ((c << shift) & 1) //01100001 & 00000001
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		shift++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid_target;
	int	i;

	if (argc != 3 || ft_atoi(argv[1]) < 1)
	{
		ft_printf("Enter valid arguments pls.\n");
		return (0);
	}
	i = 0;
	pid_target = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_msg(pid_target, argv[2][i]);
		i++;
	}
	send_msg(pid_target, '\0');
	return (0);
}

