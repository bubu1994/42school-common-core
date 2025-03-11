/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs_and_getters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:02:09 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/05/17 10:43:41 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_nb(pthread_mutex_t *mtx, size_t *nb)
{
	size_t	res;

	pthread_mutex_lock(mtx);
	res = *nb;
	pthread_mutex_unlock(mtx);
	return (res);
}

bool	get_bool(pthread_mutex_t *mtx, bool *mybool)
{
	bool	res;

	pthread_mutex_lock(mtx);
	res = *mybool;
	pthread_mutex_unlock(mtx);
	return (res);
}

void	set_bool(pthread_mutex_t *mtx, bool *mybool, bool value)
{
	pthread_mutex_lock(mtx);
	*mybool = value;
	pthread_mutex_unlock(mtx);
}

bool	char_is_in_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
			return (true);
		i++;
	}
	return (false);
}

bool	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6 || ft_atol(argv[0]) < 1)
		return (false);
	while (i < argc - 1)
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < 0
			|| char_is_in_arg(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
