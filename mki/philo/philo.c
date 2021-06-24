/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 23:02:57 by mki               #+#    #+#             */
/*   Updated: 2021/06/22 13:50:39 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_time_num(int base_time, int number, char *str)
{
	ft_putstr_fd(ft_itoa(get_time()), 1);
	write(1, " ", 1);
	ft_putstr_fd(ft_itoa(number), 1);
	write(1, " ", 1);
	ft_putstr_fd(str, 1);
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
