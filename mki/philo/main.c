/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:58:36 by mki               #+#    #+#             */
/*   Updated: 2021/06/27 17:32:59 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** base_time
** cur_time
** philos
** tids
** mutexes
*/

void	init_global(t_global *global)
{
	int	i;

	global->base_time = get_time();
	global->cur_time = 0;
	global->monitor_flag = 0;
	global->mutex_id = malloc(sizeof(pthread_mutex_t) * global->num_of_philos);
	i = -1;
	while (++i < global->num_of_philos)
		pthread_mutex_init(&(global->mutex_id)[i], NULL);
	pthread_mutex_init(&global->mutex_print, NULL);
	global->fork = malloc(sizeof(int) * global->num_of_philos);
	memset(global->fork, -1, global->num_of_philos);
	global->thread_id = malloc(sizeof(pthread_t) * global->num_of_philos);
}

void	init_philo(t_global *global, t_philo **philo)
{
	int	i;

	i = -1;
	*philo = malloc(sizeof(t_philo) * global->num_of_philos);
	while (++i < global->num_of_philos)
	{
		(*philo)[i].number = i;
		(*philo)[i].state = 0;
		(*philo)[i].old_state = 0;
		(*philo)[i].last_eat = get_time();
		(*philo)[i].eat_cnt = 0;
		if (i == 0)
			(*philo)[i].left_fork = global->num_of_philos - 1;
		else
			(*philo)[i].left_fork = i - 1;
		(*philo)[i].right_fork = i;
		(*philo)[i].global = global;
	}
}

int		philo(t_global *global)
{
	t_philo		*philo;
	int			i;

	i = -1;
	init_philo(global, &philo);
	init_global(global);
	while (++i < global->num_of_philos)
	{
		pthread_create(&(global->thread_id)[i],
		NULL, pthread_routine, &philo[i]);
		pthread_detach(global->thread_id[i]);
	}
	pthread_create(&global->tid_print, NULL, pthread_monitor, &philo);
	pthread_join(global->tid_print, NULL);
	i = -1;
	while (++i < global->num_of_philos)
		pthread_mutex_destroy(&(global->mutex_id)[i]);
	pthread_mutex_destroy(&global->mutex_print);
	return (0);
}

/*
** argv[1] = number_of_philosophers
** argv[2] = time_to_die
** argv[3] = time_to_eat
** argv[4] = time_to_sleep
** argv[5] = [number_of_times_each_philosopher_must_eat]
*/

int		main(int argc, char *argv[])
{
	t_global	global;

	if (argc != 5 && argc != 6)
		ft_putstr_fd("Wrong arguments\n", 1);
	else
	{
		global.num_of_philos = ft_atoi(argv[1]);
		global.time_to_die = ft_atoi(argv[2]);
		global.time_to_eat = ft_atoi(argv[3]);
		global.time_to_sleep = ft_atoi(argv[4]);
		global.time_must_eat = 0;
		global.time_must_eat_flag = 0;
		if (argc == 6)
			global.time_must_eat = ft_atoi(argv[5]);
		philo(&global);
	}
	return (0);
}
