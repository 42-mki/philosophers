/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:26:54 by han               #+#    #+#             */
/*   Updated: 2021/01/19 23:42:37 by han              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int
	init_semaphores(t_info *info)
{
	if ((info->sem_forks = ft_sem_open(SEM_FORK, info->p_num)) < 0
		|| (info->sem_write = ft_sem_open(SEM_WRITE, 1)) < 0
		|| (info->sem_dead = ft_sem_open(SEM_DEAD, 0)) < 0)
		return (1);
	return (0);
}

static int
	init_philos(t_info *info)
{
	int		i;
	char	semaphore[250];

	i = -1;
	while (++i < info->p_num)
	{
		info->philos[i].is_eat = 0;
		info->philos[i].index = i;
		info->philos[i].eat_count = 0;
		make_semaphore_name(SEM_PHILO, (char*)semaphore, i);
		if ((info->philos[i].mutex = ft_sem_open(semaphore, 1)) < 0)
			return (1);
		make_semaphore_name(SEM_PHILOEAT, (char*)semaphore, i);
		if ((info->philos[i].must_eat = ft_sem_open(semaphore, 0)) < 0)
			return (1);
	}
	return (0);
}

int
	init(t_info *info, int ac, char **av)
{
	info->p_num = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->must_eat_count = ac == 6 ? ft_atoi(av[5]) : 0;
	info->sem_forks = NULL;
	info->philos = NULL;
	info->cur_eat_count = 0;
	if (info->p_num < 2 || info->time_to_die < 0 || info->time_to_eat < 0
		|| info->time_to_sleep < 0 || info->must_eat_count < 0)
		return (1);
	if (!(info->philos = (t_philo*)malloc(sizeof(t_philo) * info->p_num)))
		return (1);
	if (init_semaphores(info))
		return (1);
	if (init_philos(info))
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
	sem_wait(info->sem_dead);
	free_info(info);
	return (0);
}
