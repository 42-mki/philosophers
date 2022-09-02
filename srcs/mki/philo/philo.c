/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:02:57 by mki               #+#    #+#             */
/*   Updated: 2021/06/12 12:30:23 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_var *v)
{
	printf("%u\n", v->base_time);
	printf("%u\n", v->cur_time);
}

void	init_philos(t_var *v)
{
	int	i;

	i = -1;
	v->philos = malloc(sizeof(t_philo) * v->num_of_philos);
	while (++i < v->num_of_philos)
	{
		(v->philos)[i].time_eat = 0;
		(v->philos)[i].last_eat = 0;
		(v->philos)[i].state = THINK;
		(v->philos)[i].number = i;
	}
}

void	print_time_num(int base_time, int number, char *str)
{
	ft_putstr_fd(ft_itoa(get_time(base_time)), 1);
	write(1, " ", 1);
	ft_putstr_fd(ft_itoa(number), 1);
	write(1, " ", 1);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
}

void	print_state(int base_time, int number, int state)
{
	if (state == TAKE)
		print_time_num(base_time, number, "has taken a fork\n");
	else if (state == EAT)
		print_time_num(base_time, number, "is eating\n");
	else if (state == SLEEP)
		print_time_num(base_time, number, "is sleeping\n");
	else if (state == THINK)
		print_time_num(base_time, number, "is thinking\n");
	else if (state == DIE)
		print_time_num(base_time, number, "died\n");
}

void	init_fork(t_var *v)
{
	int	i;

	i = -1;
	v->mutexes = malloc(sizeof(pthread_mutex_t) * v->num_of_philos);
	while (++i < v->num_of_philos)
		pthread_mutex_init(&(v->mutexes)[i], NULL);
}

void	pickup_fork(t_var *v, int n, int philo)
{
	pthread_mutex_lock(&(v->mutexes)[n]);
	philo = 0;
}

void	return_fork(int n)
{
	n = 0;
}

void	destory_fork(t_var *v)
{
	int	i;

	i = -1;
	while (++i < v->num_of_philos)
		pthread_mutex_destroy(&(v->mutexes[i]));
}

void	init(t_var *v)
{
	v->base_time = init_time();
	v->cur_time = get_time(v->base_time);
	init_philos(v);
	v->end = 0;
	v->tids = malloc(sizeof(pthread_t) * v->num_of_philos);
	init_fork(v);
}

void	*thread_routine(void *arg)
{
	return (arg);
}

void	*thread_print(void *arg)
{
	return (arg);
}

int		philo(t_var *v)
{
	int	i;

	init(v);
	i = -1;
	while (++i < v->num_of_philos)
	{
		pthread_create(&(v->tids)[i], NULL, thread_routine, NULL);
		pthread_detach(v->tids[i]);
	}
	pthread_create(&v->tid_print, NULL, thread_print, NULL);
	pthread_join(v->tid_print, NULL);
	print(v);
	free(v->philos);
	free(v->tids);
	return (0);
}
