/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:32:44 by mki               #+#    #+#             */
/*   Updated: 2021/06/24 22:14:47 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*pthread_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("num: %d\n", philo->number);
	while (1)
	{
		taken_fork(philo->global, philo->number, philo->number);
		if (philo->number == 0)
			taken_fork(philo->global, philo->global->num_of_philos - 1, philo->number);
		else
			taken_fork(philo->global, philo->number - 1, philo->number);
		// if ( && eating())
		// 	break ;
		// return_fork();
		// return_fork();
		// if (sleeping())
		// 	break ;
		// if (thinking())
		// 	break ;
	}
	return (arg);
}

void	*pthread_monitor(void *arg)
{
	// t_philo	*philos;
	// long	cur_time;
	// int		time_to_die;
	// int		num_of_philos;
	// int		i;

	// philos = (t_philo *)arg;
	// time_to_die = philos[0]->global->time_to_die;
	// num_of_philos = philos[0]->global->num_of_philos;
	// i = -1;
	// while (!philos[0]->global->monitor_flag)
	// {
	// 	while (++i < num_of_philos)
	// 	{
	// 		cur_time = get_time();
	// 		printf("%lu\n", cur_time);
	// 		if (cur_time - philos[i]->last_eat >= time_to_die)
	// 		{
	// 			print_state(cur_time - philos[i]->last_eat, i, DIE);
	// 			philos[i]->global->monitor_flag = 1;
	// 			break ;
	// 		}
	// 	}
	// 	my_usleep(1);
	// }
	return (arg);
}
