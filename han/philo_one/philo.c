/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 18:19:32 by han               #+#    #+#             */
/*   Updated: 2021/01/20 16:00:47 by han              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void
	*monitor_count(void *info_v)
{
	t_info	*info;
	int		i;
	int		total;

	info = (t_info*)info_v;
	total = 0;
	while (total < info->must_eat_count)
	{
		i = 0;
		while (i < info->p_num)
			pthread_mutex_lock(&info->philos[i++].must_eat);
		total++;
	}
	dp_msg(&info->philos[0], T_OVER);
	pthread_mutex_unlock(&info->mt_dead);
	return ((void*)0);
}

static void
	*monitor(void *philo_v)
{
	t_philo		*philo;

	philo = (t_philo*)philo_v;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eat && get_time() > philo->limit)
		{
			dp_msg(philo, T_DIED);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&get_info()->mt_dead);
			return ((void*)0);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
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
	start_threads(t_info *info)
{
	int			i;
	pthread_t	tid;
	void		*philo;

	info->start_time = get_time();
	if (info->must_eat_count > 0)
	{
		if (pthread_create(&tid, NULL, &monitor_count, (void*)info) != 0)
			return (1);
		pthread_detach(tid);
	}
	i = 0;
	while (i < info->p_num)
	{
		philo = (void*)(&info->philos[i]);
		if (pthread_create(&tid, NULL, &routine, philo) != 0)
			return (1);
		pthread_detach(tid);
		usleep(100);
		i++;
	}
	return (0);
}
