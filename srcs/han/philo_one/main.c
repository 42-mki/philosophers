/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:41:25 by han               #+#    #+#             */
/*   Updated: 2021/01/20 16:02:23 by han              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int
	init_mutex(t_info *info)
{
	int		i;

	i = 0;
	pthread_mutex_init(&info->mt_write, NULL);
	pthread_mutex_init(&info->mt_dead, NULL);
	pthread_mutex_lock(&info->mt_dead);
	if (!(info->mt_forks =
		(pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * info->p_num)))
		return (1);
	while (i < info->p_num)
		pthread_mutex_init(&info->mt_forks[i++], NULL);
	return (0);
}

static void
	init_philos(t_info *info)
{
	int		i;

	i = -1;
	while (++i < info->p_num)
	{
		info->philos[i].is_eat = 0;
		info->philos[i].index = i;
		info->philos[i].lfork = i;
		info->philos[i].rfork = (i + 1) % info->p_num;
		info->philos[i].eat_count = 0;
		pthread_mutex_init(&info->philos[i].mutex, NULL);
		pthread_mutex_init(&info->philos[i].must_eat, NULL);
		pthread_mutex_lock(&info->philos[i].must_eat);
	}
}

int
	init(t_info *info, int ac, char **av)
{
	info->p_num = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->must_eat_count = ac == 6 ? ft_atoi(av[5]) : 0;
	info->mt_forks = NULL;
	info->philos = NULL;
	if (info->p_num < 2 || info->time_to_die < 0 || info->time_to_eat < 0
		|| info->time_to_sleep < 0 || info->must_eat_count < 0)
		return (1);
	if (!(info->philos = (t_philo*)malloc(sizeof(t_philo) * info->p_num)))
		return (1);
	init_philos(info);
	if (init_mutex(info))
		return (1);
	return (0);
}

int
	main(int ac, char **av)
{
	t_info		*info;

	if (ac < 5 || ac > 6)
		return (exit_error("Error : bac arguments\n"));
	info = get_info();
	if (init(info, ac, av))
		return (free_info(info) && exit_error("Error : Fatal"));
	if (start_threads(info))
		return (free_info(info) && exit_error("Error : Fatal"));
	pthread_mutex_lock(&info->mt_dead);
	pthread_mutex_unlock(&info->mt_dead);
	free_info(info);
	return (0);
}
