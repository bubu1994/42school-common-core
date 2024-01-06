/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:53:36 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/06 15:12:20 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	doubles_are_not_in(char **argv)
{
	int	i;
	int	n;
	int	j;

	i = 0;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[j]) == n)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	args_are_int(char **argv)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	args_are_digits(char **argv)
{
	int	i;
	int	k;

	if (*argv == NULL || **argv == '\0')
		return (0);
	i = 0;
	while (argv[i])
	{
		k = 0;
		if (argv[i][k] == '-' || argv[i][k] == '+')
			k++;
		if (argv[i][k] == '\0')
			return (0);
		while (argv[i][k])
		{
			if (argv[i][k] > '9' || argv[i][k] < '0')
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	check_args(char **argv)
{
	if (args_are_digits(argv) && args_are_int(argv) && doubles_are_not_in(argv))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (args_are_int(argv + 1))
		printf("ok\n");
	else
		printf("not ok\n");
	return (0);
}*/