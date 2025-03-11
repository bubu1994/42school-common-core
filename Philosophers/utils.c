/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:57:19 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/05/17 12:36:59 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	nb;

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

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Erreur gettimeofday()\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(200);
	return (0);
}

void	mutexes_destroyer(t_philo *filos, t_fork *forks, t_data *table)
{
	int	i;

	i = -1;
	while (++i < filos->table->nb_philos)
	{
		pthread_mutex_destroy(&filos[i].meal_lock);
		pthread_mutex_destroy(&forks[i].mtx);
	}
	pthread_mutex_destroy(&table->end_lock);
	pthread_mutex_destroy(&table->print_lock);
}

void	print_action(char *action, t_philo *filo)
{
	pthread_mutex_lock(&filo->table->print_lock);
	printf("%zu %d %s\n", get_current_time()
		- filo->table->start_timestp, filo->id, action);
	pthread_mutex_unlock(&filo->table->print_lock);
}

/*
void	print_action_rf(char *action, t_philo *filo)
{
	pthread_mutex_lock(&filo->table->print_lock);
	printf("%zu %d %s %d\n", get_current_time()
		- filo->table->start_timestp, filo->id, action, filo->right_fork->id);
	pthread_mutex_unlock(&filo->table->print_lock);
}

void	print_action_lf(char *action, t_philo *filo)
{
	pthread_mutex_lock(&filo->table->print_lock);
	printf("%zu %d %s %d\n", get_current_time()
		- filo->table->start_timestp, filo->id, action, filo->left_fork->id);
	pthread_mutex_unlock(&filo->table->print_lock);
}


usleep (qui suspend le programme en microsecondes données) n'etant pas precis
pour de grandes valeurs, on l'utilise pour "voir" à chaque boucle de 0.2
milliseconde, si on a passé le temps donné en paramètre.

get_current_time retourne un horodatage(timestamp) en millisecondes


*/