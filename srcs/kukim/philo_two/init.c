/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:04:43 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 17:12:05 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	launch_threads(t_philo *ph)
{
	int				i;

	i = -1;
	while (ph[++i].id)
		pthread_create(&(ph[i].thread), NULL, &philo_life, &(ph[i]));
}

void	init_t_info(t_info *info, int ac, char **av)
{
	info->nb_ph = ft_atoi(av[1]);
	info->t_to_die = ft_atoi(av[2]);
	info->t_to_eat = ft_atoi(av[3]);
	info->t_to_sleep = ft_atoi(av[4]);
	info->nb_each_ph_eat = ac == 6 ? ft_atoi(av[5]) : -1;
}

int		init_semaphore(t_philo *ph, t_info *info)
{
	int		nb_ph;
	sem_t	*nb_forks;
	sem_t	*printing;
	sem_t	*take_forks;

	nb_ph = info->nb_ph;
	printing = NULL;
	sem_unlink(S_FORKS);
	sem_unlink(S_PRINT);
	sem_unlink(S_TAKE);
	nb_forks = sem_open(S_FORKS, O_CREAT, 0644, nb_ph / 2);
	printing = sem_open(S_PRINT, O_CREAT, 0644, 1);
	take_forks = sem_open(S_TAKE, O_CREAT, 0644, 1);
	while (--nb_ph >= 0)
	{
		(ph[nb_ph]).nb_forks = nb_forks;
		(ph[nb_ph]).printing = printing;
		(ph[nb_ph]).take_forks = take_forks;
	}
	return (SUCCESS);
}

t_philo	*create_t_philo_array(t_info *info, int *nb_ph_fed, int *ph_die)
{
	t_philo	*ph;
	int		nb_ph;
	long	time_start;

	nb_ph = info->nb_ph;
	if (!(ph = malloc(sizeof(*ph) * (nb_ph + 1))))
		return (NULL);
	ph[nb_ph].id = 0;
	init_semaphore(ph, info);
	time_start = get_time_ms();
	while (nb_ph - 1 >= 0)
	{
		ph[nb_ph - 1].id = nb_ph;
		ph[nb_ph - 1].info = info;
		ph[nb_ph - 1].time_start = time_start;
		ph[nb_ph - 1].ph_die = ph_die;
		ph[nb_ph - 1].nb_ph_fed = nb_ph_fed;
		nb_ph--;
	}
	return (ph);
}
