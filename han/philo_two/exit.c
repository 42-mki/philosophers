/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:26:32 by han               #+#    #+#             */
/*   Updated: 2021/01/19 20:07:52 by han              ###   ########.fr       */
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
	int		i;
	char	semaphore[255];

	sem_unlink(SEM_FORK);
	sem_unlink(SEM_WRITE);
	sem_unlink(SEM_DEAD);
	if (info->philos)
	{
		i = 0;
		while (i < info->p_num)
		{
			make_semaphore_name(SEM_PHILO, (char*)semaphore, i);
			sem_unlink(semaphore);
			make_semaphore_name(SEM_PHILOEAT, (char*)semaphore, i++);
			sem_unlink(semaphore);
		}
		free(info->philos);
	}
	return (EXIT_FAILURE);
}
