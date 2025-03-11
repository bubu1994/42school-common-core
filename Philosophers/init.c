/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:28:27 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/05/17 12:02:43 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ret_check(int ret)
{
	if (ret != 0)
	{
		printf("Erreur pthread_create/join\n");
		return (1);
	}
	return (0);
}

t_data	*init_table(char **argv)
{
	t_data			*table;

	table = malloc(sizeof(t_data));
	if (!table)
		return (NULL);
	table->nb_philos = ft_atol(argv[1]);
	table->die_time = ft_atol(argv[2]);
	table->eat_time = ft_atol(argv[3]);
	table->sleep_time = ft_atol(argv[4]);
	if (argv[5])
		table->must_eat_times = ft_atol(argv[5]);
	else
		table->must_eat_times = 2147483647;
	table->start_timestp = get_current_time();
	table->the_end = false;
	pthread_mutex_init(&table->end_lock, NULL);
	pthread_mutex_init(&table->print_lock, NULL);
	return (table);
}

t_fork	*init_forks(int nb_philos)
{
	t_fork	*forks;
	int		i;

	forks = malloc(sizeof(t_fork) * nb_philos);
	if (!forks)
		return (NULL);
	i = -1;
	while (++i < nb_philos)
	{
		forks[i].id = i;
		pthread_mutex_init(&forks[i].mtx, NULL);
	}
	return (forks);
}

t_philo	*init_filos(t_data *table, t_fork *forks)
{
	t_philo	*filos;
	int		i;

	i = -1;
	filos = malloc(sizeof(t_philo) * table->nb_philos);
	if (!filos)
		return (NULL);
	while (++i < table->nb_philos)
	{
		filos[i].table = table;
		filos[i].last_meal_timestp = table->start_timestp;
		filos[i].id = i + 1;
		filos[i].right_fork = &forks[i];
		if (table->nb_philos != 1)
		{
			if (i == table->nb_philos - 1)
				filos[i].left_fork = &forks[0];
			else
				filos[i].left_fork = &forks[i + 1];
		}
		filos[i].meals_eaten = 0;
		pthread_mutex_init(&filos[i].meal_lock, NULL);
	}
	return (filos);
}

/*
On attribue à un philo sa propre fourchette et la fourchette à sa gauche
*/