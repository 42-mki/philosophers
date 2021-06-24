/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:58:36 by mki               #+#    #+#             */
/*   Updated: 2021/06/24 13:56:27 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** a
*/

int		philo(t_var *v)
{
	int	i;

	i = -1;
	while (++i < v->num_of_philos)
	{
		pthread_create(&(v->tids)[i], NULL, pthread_routine, NULL);
		pthread_detach(v->tids[i]);
	}
	pthread_create(&v->tid_print, NULL, pthread_print, NULL);
	pthread_join(v->tid_print, NULL);
	return (0);
}

/*
** base_time
** cur_time
** philos
** tids
** mutexes
*/

void	init(t_var *v)
{
	int	i;

	v->base_time = get_time();
	v->cur_time = 0;
	i = -1;
	v->philos = malloc(sizeof(t_philo) * v->num_of_philos);
	while (++i < v->num_of_philos)
	{
		(v->philos)[i].time_eat = 0;
		(v->philos)[i].last_eat = 0;
		(v->philos)[i].state = 0;
		(v->philos)[i].number = i;
	}
	v->tids = malloc(sizeof(pthread_t) * v->num_of_philos);
	v->mutexes = malloc(sizeof(pthread_mutex_t) * v->num_of_philos);
	i = -1;
	while (++i < v->num_of_philos)
		pthread_mutex_init(&(v->mutexes)[i], NULL);
}

void	free_all(t_var *v)
{
	int	i;

	free(v->philos);
	free(v->tids);
	free(v->mutexes);
	i = -1;
	while (++i < v->num_of_philos)
		pthread_mutex_destroy(&(v->mutexes)[i]);
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
	t_var	var;

	if (argc != 5 && argc != 6)
		ft_putstr_fd("Wrong arguments\n", 1);
	else
	{
		var.num_of_philos = ft_atoi(argv[1]);
		var.time_to_die = ft_atoi(argv[2]);
		var.time_to_eat = ft_atoi(argv[3]);
		var.time_to_sleep = ft_atoi(argv[4]);
		var.time_must_eat = 0;
		if (argc == 6)
			var.time_must_eat = ft_atoi(argv[5]);
		init(&var);
		philo(&var);
		free_all(&var);
	}
	system("leaks philo");
	return (0);
}
