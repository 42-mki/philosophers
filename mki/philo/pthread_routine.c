/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:32:44 by mki               #+#    #+#             */
/*   Updated: 2021/06/27 17:41:25 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	take_fork(t_philo *philo)
{
	if (philo->number % 2 == 1)
		usleep(200);
	taken_fork(philo, philo->right_fork, philo->number);
	taken_fork(philo, philo->left_fork, philo->number);
}

void	eating(t_philo *philo)
{
	if (philo->global->fork[philo->left_fork] == philo->number &&
		philo->global->fork[philo->right_fork] == philo->number)
	{
		philo->state = EAT;
		philo->last_eat = get_time();
		print_state(philo->global,
		get_time() - philo->global->base_time, philo->number, philo->state);
		philo->eat_cnt++;
	}
	my_usleep(philo->global->time_to_eat);
}

void	sleeping(t_philo *philo)
{
	philo->state = SLEEP;
	print_state(philo->global,
	get_time() - philo->global->base_time, philo->number, philo->state);
	return_fork(philo, philo->right_fork, philo->left_fork);
	my_usleep(philo->global->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	philo->state = THINK;
	print_state(philo->global,
	get_time() - philo->global->base_time, philo->number, philo->state);
}

void	*pthread_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(100);
		take_fork(philo);
		eating(philo);
		usleep(100);
		sleeping(philo);
		usleep(100);
		thinking(philo);
	}
	return (arg);
}
