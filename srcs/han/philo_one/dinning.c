/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:37:48 by han               #+#    #+#             */
/*   Updated: 2021/01/19 18:55:51 by han              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	eat(t_philo *philo)
{
	t_info		*info;

	info = get_info();
	pthread_mutex_lock(&philo->mutex);
	philo->is_eat = 1;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + info->time_to_die;
	dp_msg(philo, T_EAT);
	usleep(info->time_to_eat * 1000);
	philo->eat_count++;
	philo->is_eat = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->must_eat);
}

void
	take_forks(t_philo *philo)
{
	t_info		*info;

	info = get_info();
	pthread_mutex_lock(&info->mt_forks[philo->lfork]);
	dp_msg(philo, T_FORK);
	pthread_mutex_lock(&info->mt_forks[philo->rfork]);
	dp_msg(philo, T_FORK);
}

void
	down_forks(t_philo *philo)
{
	t_info		*info;

	info = get_info();
	dp_msg(philo, T_SLEEP);
	pthread_mutex_unlock(&info->mt_forks[philo->lfork]);
	pthread_mutex_unlock(&info->mt_forks[philo->rfork]);
	usleep(info->time_to_sleep * 1000);
}
