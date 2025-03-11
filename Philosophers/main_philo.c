/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:30:30 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/05/17 12:37:10 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eats_2(t_philo *filo)
{
	print_action("has taken a fork", filo);
	print_action("is eating", filo);
	pthread_mutex_lock(&filo->meal_lock);
	filo->last_meal_timestp = get_current_time();
	filo->meals_eaten++;
	pthread_mutex_unlock(&filo->meal_lock);
	ft_usleep(filo->table->eat_time);
	pthread_mutex_unlock(&filo->right_fork->mtx);
	pthread_mutex_unlock(&filo->left_fork->mtx);
	if (get_bool(&filo->table->end_lock, &filo->table->the_end))
		return ;
	print_action("is sleeping", filo);
	ft_usleep(filo->table->sleep_time);
	if (get_bool(&filo->table->end_lock, &filo->table->the_end))
		return ;
	print_action("is thinking", filo);
}

void	eats(t_philo *filo)
{
	pthread_mutex_lock(&filo->right_fork->mtx);
	if (get_bool(&filo->table->end_lock, &filo->table->the_end))
	{	
		pthread_mutex_unlock(&filo->right_fork->mtx);
		return ;
	}
	print_action("has taken a fork", filo);
	if (filo->table->nb_philos == 1)
	{
		ft_usleep(filo->table->die_time);
		pthread_mutex_unlock(&filo->right_fork->mtx);
		return ;
	}
	pthread_mutex_lock(&filo->left_fork->mtx);
	if (get_bool(&filo->table->end_lock, &filo->table->the_end))
	{	
		pthread_mutex_unlock(&filo->right_fork->mtx);
		pthread_mutex_unlock(&filo->left_fork->mtx);
		return ;
	}
	eats_2(filo);
}

void	*routine(void *arg)
{
	t_philo	*filo;

	filo = (t_philo *)arg;
	if (filo->id % 2 == 0)
		usleep(400);
	while (!get_bool(&filo->table->end_lock, &filo->table->the_end))
	{
		eats(filo);
	}
	return (NULL);
}

void	start_diner(t_philo *filos)
{
	int			i;
	pthread_t	monitor;

	ret_check(pthread_create(&monitor, NULL, monitoring, (void *)filos));
	i = -1;
	while (++i < filos->table->nb_philos)
		ret_check(pthread_create(&filos[i].thread, NULL, routine,
				(void *)&filos[i]));
	ret_check(pthread_join(monitor, NULL));
	i = -1;
	while (++i < filos->table->nb_philos)
		ret_check(pthread_join(filos[i].thread, NULL));
}

int	main(int argc, char **argv)
{
	t_data	*table;
	t_philo	*filos;
	t_fork	*forks;

	if (check_args(argc, argv + 1) == false)
	{
		printf("Arguments invalides\n");
		return (0);
	}
	table = init_table(argv);
	forks = init_forks(table->nb_philos);
	filos = init_filos(table, forks);
	start_diner(filos);
	mutexes_destroyer(filos, forks, table);
	free(filos);
	free(table);
	free(forks);
	return (0);
}

/*
"Pile(stack) ou Tas(heap), que choisir ?
· Vous devez allouer un grand bloc de mémoire (grande liste par exemple) et 
la variable doit pouvoir être modifiable et accessible pendant une longue 
période : Le tas sera votre meilleur allié !
· Vous utilisez des petites variables dont la portée ne dépasse pas la fonction 
qui les utilise : utilisez la pile, c’est plus facile et plus rapide."

"Une data race (ou "condition de concurrence" en français) est une situation en
programmation concurrente où deux threads ou plus accèdent à la même mémoire
partagée simultanément, et au moins un de ces accès est une écriture, sans que
ces accès soient correctement synchronisés. Les data races peuvent entraîner
des comportements imprévisibles, des résultats incorrects, des bogues
difficiles à reproduire et à déboguer."

compiler avec -fsanitize=thread pour checker des race conditions, mais RALENTIT
l'execution du programme, NE PAS LAISSER dans la version finale.

Au debut de la routine, les philos pairs attendent 500 microsecondes pour que
chacun ne prenne pas une fourchette en meme temps (sinon boucle infinie)

Des qu'une ressource est partagée (modifiée ou LUE) par plusieurs threads, il
faut la protéger avec un mutex(mutual exclusion). "Lorsqu'un thread souhaite
accéder à une ressource partagée protégée par un mutex, il doit d'abord
verrouiller le mutex en appelant pthread_mutex_lock. Si le mutex est déjà
verrouillé par un autre thread, le thread appelant est bloqué jusqu'à ce que
le mutex devienne disponible.
1. lock 2. ecrire/lire 3. unlock

Les moniteur lit les variables 'meals_eaten' 'last_meal_timestp' 'the_end' et 
écrit sur 'the_end'
Un philo lit 'the_end' et écrit sur 'meals_eaten' 'last_meal_timestp'
Les mutexes:
-les forks
-meal_lock: 'meals_eaten' 'last_meal_timestp'
-end_lock: 'the_end'
-print_lock: pour protéger le printing et ne pas mélanger les messages. 

L'ordre des instructions est primordiale.

get/set_bool: pour changer la valeur appelé comme paramètre, il faut le passer 
par un pointeur !!!!!!!
"there's an issue with the way the mutex is used. In C and C++, mutexes are
typically passed by pointer, not by value. This is because passing a mutex by
value would create a copy of the mutex, defeating its purpose.

un philo peut mourir pendant qu'il mange (consigne)
*/