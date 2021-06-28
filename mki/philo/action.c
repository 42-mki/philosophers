/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:40:03 by mki               #+#    #+#             */
/*   Updated: 2021/06/28 19:11:23 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	taken_fork(t_philo *philo, int left, int right, int philo_num)
{
	pthread_mutex_lock(&philo->global->mutex_id[left]);
	pthread_mutex_lock(&philo->global->mutex_id[right]);
	philo->global->fork[left] = philo_num;
	philo->global->fork[right] = philo_num;
	philo->state = TAKE;
	print_state(philo->global,
	get_time() - philo->global->base_time, philo->number, philo->state);
}

void	return_fork(t_philo *philo, int right_fork, int left_fork)
{
	philo->global->fork[right_fork] = -1;
	philo->global->fork[left_fork] = -1;
	pthread_mutex_unlock(&philo->global->mutex_id[right_fork]);
	pthread_mutex_unlock(&philo->global->mutex_id[left_fork]);
}
