/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:26:12 by han               #+#    #+#             */
/*   Updated: 2021/01/19 22:21:50 by han              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	eat(t_philo *philo)
{
	t_info		*info;

	info = get_info();
	sem_wait(philo->mutex);
	philo->is_eat = 1;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + info->time_to_die;
	dp_msg(philo, T_EAT);
	usleep(info->time_to_eat * 1000);
	philo->eat_count++;
	philo->is_eat = 0;
	sem_post(philo->mutex);
	sem_post(philo->must_eat);
	return (0);
}

int
	take_forks(t_philo *philo)
{
	t_info		*info;

	info = get_info();
	sem_wait(info->sem_forks);
	dp_msg(philo, T_FORK);
	sem_wait(info->sem_forks);
	dp_msg(philo, T_FORK);
	return (0);
}

int
	down_forks(t_philo *philo)
{
	t_info		*info;

	info = get_info();
	dp_msg(philo, T_SLEEP);
	sem_post(info->sem_forks);
	sem_post(info->sem_forks);
	usleep(info->time_to_sleep * 1000);
	return (0);
}
