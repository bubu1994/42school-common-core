/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:15:39 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/05/17 10:49:09 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_death(t_philo *filos)
{
	int		i;

	i = -1;
	while (++i < filos->table->nb_philos)
	{
		if (get_current_time() - get_nb(&filos[i].meal_lock,
				&filos[i].last_meal_timestp) >= (size_t) filos->table->die_time
			&& !get_bool(&filos->table->end_lock, &filos->table->the_end))
		{
			print_action("died", &filos[i]);
			return (true);
		}
	}
	return (false);
}

bool	check_fullness(t_philo *filos)
{
	int	i;

	i = -1;
	while (++i < filos->table->nb_philos)
	{
		pthread_mutex_lock(&filos[i].meal_lock);
		if (filos[i].meals_eaten < filos[i].table->must_eat_times)
		{
			pthread_mutex_unlock(&filos[i].meal_lock);
			return (false);
		}
		pthread_mutex_unlock(&filos[i].meal_lock);
	}
	return (true);
}

void	*monitoring(void *arg)
{
	t_philo	*filos;

	filos = (t_philo *)arg;
	while (1)
	{
		if (check_fullness(filos) || check_death(filos))
			break ;
	}
	set_bool(&filos->table->end_lock, &filos->table->the_end, true);
	return (NULL);
}
