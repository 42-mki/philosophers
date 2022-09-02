/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:26:13 by han               #+#    #+#             */
/*   Updated: 2021/01/20 17:43:07 by han              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void
	*monitor_count(void *info_v)
{
	t_info	*info;
	int		i;

	info = (t_info*)info_v;
	while (info->cur_eat_count < info->must_eat_count)
	{
		i = 0;
		while (i < info->p_num)
			sem_wait(info->philos[i++].must_eat);
		info->cur_eat_count++;
	}
	dp_msg(&info->philos[0], T_OVER);
	sem_post(info->sem_dead);
	return ((void*)0);
}

static void
	*monitor(void *philo_v)
{
	t_philo		*philo;

	philo = (t_philo*)philo_v;
	while (1)
	{
		sem_wait(philo->mutex);
		if (!philo->is_eat && get_time() > philo->limit)
		{
			dp_msg(philo, T_DIED);
			sem_post(philo->mutex);
			sem_post(get_info()->sem_dead);
			return ((void*)0);
		}
		sem_post(philo->mutex);
		usleep(1000);
	}
	return ((void*)0);
}

static void
	*routine(void *philo_v)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo*)philo_v;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + get_info()->time_to_die;
	if (pthread_create(&tid, NULL, &monitor, philo_v) != 0)
		return ((void*)1);
	pthread_detach(tid);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		down_forks(philo);
		dp_msg(philo, T_THINK);
	}
	return ((void*)0);
}

int
	start_monitor_thread(t_info *info)
{
	pthread_t	tid;

	if (info->must_eat_count > 0)
	{
		if (pthread_create(&tid, NULL, &monitor_count, (void*)info) != 0)
			return (1);
		pthread_detach(tid);
	}
	return (0);
}

int
	start_process(t_info *info)
{
	int			i;
	void		*philo;

	info->start_time = get_time();
	i = 0;
	while (i < info->p_num)
	{
		philo = (void*)(&info->philos[i]);
		info->philos[i].pid = fork();
		if (info->philos[i].pid < 0)
			return (1);
		else if (info->philos[i].pid == 0)
		{
			routine(&info->philos[i]);
			exit(0);
		}
		usleep(100);
		i++;
	}
	return (0);
}
