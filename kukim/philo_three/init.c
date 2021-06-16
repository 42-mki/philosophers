/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:18:14 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 19:15:38 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*wait_until_all_fed(void *tmp)
{
	t_philo	*ph;
	int		i;

	ph = (t_philo *)tmp;
	i = ph->info->nb_ph;
	if (ph->info->nb_each_ph_eat != -1)
		while (--i >= 0)
			sem_wait(ph->nb_ph_fed);
	if (ph->info->nb_each_ph_eat != -1)
	{
		sem_wait(ph->printing);
		sem_post(ph->ph_die);
		ft_putstr_fd("All philosphers have eaten enough\n", 1);
	}
	return (tmp);
}

pid_t	*pid_malloc(const t_philo *ph)
{
	pid_t		*pid;

	if (!(pid = malloc(sizeof(*pid) * ph->info->nb_ph)))
		exit(error_msg("Fatal error : malloc failed\n"));
	return (pid);
}

void	launch_processes(t_philo *ph)
{
	int				i;
	pid_t			*pid;
	pthread_t		control_nb_ph_fed;

	i = -1;
	pid = pid_malloc(ph);
	pthread_create(&control_nb_ph_fed, NULL, &wait_until_all_fed, (void *)ph);
	while (++i < ph->info->nb_ph)
	{
		if ((pid[i] = fork()) < 0)
			exit(error_msg("Fatal error : fork failed\n"));
		else if (!pid[i])
		{
			ph->id = i + 1;
			philo_life(ph);
		}
	}
	sem_wait(ph->ph_die);
	while (--i >= 0)
		kill(pid[i], SIGINT);
	i = ph->info->nb_each_ph_eat;
	ph->info->nb_each_ph_eat = -1;
	while (--i >= 0)
		sem_post(ph->nb_ph_fed);
	free(pid);
}

void	init_t_info(t_info *info, int ac, char **av)
{
	info->nb_ph = ft_atoi(av[1]);
	info->t_to_die = ft_atoi(av[2]);
	info->t_to_eat = ft_atoi(av[3]);
	info->t_to_sleep = ft_atoi(av[4]);
	info->nb_each_ph_eat = ac == 6 ? ft_atoi(av[5]) : -1;
}

int		create_t_philo_array(t_philo *ph, t_info *info)
{
	ph->time_start = get_time_ms();
	ph->info = info;
	sem_unlink(S_FORKS);
	sem_unlink(S_PRINT);
	sem_unlink(S_TAKE);
	sem_unlink(S_PHILO_DIE);
	sem_unlink(S_NB_PH_FED);
	ph->nb_forks = sem_open(S_FORKS, O_CREAT, 0644, info->nb_ph / 2);
	ph->printing = sem_open(S_PRINT, O_CREAT, 0644, 1);
	ph->take_forks = sem_open(S_TAKE, O_CREAT, 0644, 1);
	ph->ph_die = sem_open(S_PHILO_DIE, O_CREAT, 0644, 0);
	ph->nb_ph_fed = sem_open(S_NB_PH_FED, O_CREAT, 0644, 0);
	return (SUCCESS);
}
