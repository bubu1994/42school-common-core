/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:31:16 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/05/17 12:35:17 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

struct s_fork
{
	int				id;
	pthread_mutex_t	mtx;
};

struct s_philo
{
	pthread_t		thread;
	int				id;
	t_fork			*right_fork;
	t_fork			*left_fork;
	size_t			last_meal_timestp;
	int				meals_eaten;
	t_data			*table;
	pthread_mutex_t	meal_lock;
};

struct s_data
{
	int				nb_philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat_times;
	size_t			start_timestp;
	bool			the_end;
	pthread_mutex_t	end_lock;
	pthread_mutex_t	print_lock;
};

long	ft_atol(const char *str);
bool	check_args(int argc, char **argv);
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);
void	mutexes_destroyer(t_philo *filos, t_fork *forks,
			t_data *table);
bool	get_bool(pthread_mutex_t *mtx, bool *mybool);
void	set_bool(pthread_mutex_t *mtx, bool *mybool, bool value);
size_t	get_nb(pthread_mutex_t *mtx, size_t *nb);
t_data	*init_table(char **argv);
t_philo	*init_filos(t_data *table, t_fork *forks);
t_fork	*init_forks(int nb_philos);
void	*monitoring(void *arg);
void	print_action(char *action, t_philo *filo);
int		ret_check(int ret);
void	print_action_rf(char *action, t_philo *filo);
void	print_action_lf(char *action, t_philo *filo);

#endif