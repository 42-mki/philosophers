/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:32:44 by mki               #+#    #+#             */
/*   Updated: 2021/06/27 17:41:24 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		time_must_eat_monitor(t_philo *philo, t_global *global)
{
	int	i;

	if (global->time_must_eat &&
		global->time_must_eat_flag == global->num_of_philos)
		return (1);
	i = -1;
	while (++i < global->num_of_philos)
	{
		if (philo[i].eat_cnt == global->time_must_eat)
		{
			global->time_must_eat_flag++;
			philo[i].eat_cnt++;
		}
	}
	return (0);
}

int		time_to_die_monitor(t_philo *philo, t_global *global)
{
	int	i;
	int	time;

	i = -1;
	time = 0;
	while (++i < global->num_of_philos)
	{
		time = get_time() - philo[i].last_eat;
		if (time >= global->time_to_die)
		{
			print_state(global, time, i, DIE);
			global->monitor_flag = 1;
			return (1);
		}
		if (philo[i].eat_cnt == global->time_must_eat)
		{
			global->time_must_eat_flag++;
			philo[i].eat_cnt++;
		}
	}
	return (0);
}

void	*pthread_monitor(void *arg)
{
	t_philo		**philos;
	t_philo		*philo;
	t_global	*global;

	philos = (t_philo **)arg;
	philo = *philos;
	global = philo[0].global;
	while (1)
	{
		if (time_must_eat_monitor(philo, global))
			break ;
		if (time_to_die_monitor(philo, global))
			break ;
		usleep(300);
	}
	return (arg);
}
