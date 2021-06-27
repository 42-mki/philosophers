/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:32:44 by mki               #+#    #+#             */
/*   Updated: 2021/06/25 16:31:48 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*pthread_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->number % 2 == 1)
			usleep(200);
		taken_fork(philo, philo->right_fork, philo->number);
		taken_fork(philo, philo->left_fork, philo->number);
		if (philo->global->fork[philo->left_fork] == philo->number &&
			philo->global->fork[philo->right_fork] == philo->number)
		{
			philo->state = EAT;
			print_state(&philo->global->mutex_print,
			get_time() - philo->global->base_time, philo->number, philo->state);
		}
		my_usleep(philo->global->time_to_eat);
		philo->eat_cnt++;
		philo->state = SLEEP;
		print_state(&philo->global->mutex_print,
		get_time() - philo->global->base_time, philo->number, philo->state);
		return_fork(philo, philo->right_fork, philo->left_fork);
		usleep(100);
		my_usleep(philo->global->time_to_sleep);
		philo->state = THINK;
		print_state(&philo->global->mutex_print,
		get_time() - philo->global->base_time, philo->number, philo->state);
		usleep(100);
	}
	return (arg);
}

void	*pthread_monitor(void *arg)
{
	int		num_of_philos;
	t_philo	**philo;

	philo = (t_philo **)arg;
	num_of_philos = (*philo)[0].global->num_of_philos;
	while (1)
	{
		usleep(100);
	}
	return (arg);
}
