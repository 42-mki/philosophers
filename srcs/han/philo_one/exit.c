/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:04:57 by han               #+#    #+#             */
/*   Updated: 2021/01/19 18:55:28 by han              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	exit_error(const char *msg)
{
	if (msg)
		write(1, msg, ft_strlen(msg));
	return (EXIT_FAILURE);
}

int
	free_info(t_info *info)
{
	int	i;

	if (info->mt_forks)
	{
		i = 0;
		while (i < info->p_num)
			pthread_mutex_destroy(&info->mt_forks[i++]);
		free(info->mt_forks);
	}
	if (info->philos)
	{
		i = 0;
		while (i < info->p_num)
		{
			pthread_mutex_destroy(&info->philos[i].mutex);
			pthread_mutex_destroy(&info->philos[i++].must_eat);
		}
		free(info->philos);
	}
	pthread_mutex_destroy(&info->mt_write);
	pthread_mutex_destroy(&info->mt_dead);
	return (EXIT_FAILURE);
}
