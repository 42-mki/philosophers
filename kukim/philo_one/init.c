/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:54:24 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 16:41:19 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			launch_threads(t_philo *ph)
{
	int				i;

	i = -1;
	while (ph[++i].id)
		pthread_create(&(ph[i].thread), NULL, &philo_life, &(ph[i]));
}

pthread_mutex_t	*create_forks(int nb_forks)
{
	pthread_mutex_t	*mutex;
	int				i;

	i = 0;
	if (!(mutex = malloc(sizeof(*mutex) * (nb_forks))))
		return (NULL);
	while (i < nb_forks)
		pthread_mutex_init(&mutex[i++], NULL);
	return (mutex);
}

void			init_t_info(t_info *info, int ac, char **av)
{
	info->nb_ph = ft_atoi(av[1]);
	info->t_to_die = ft_atoi(av[2]);
	info->t_to_eat = ft_atoi(av[3]);
	info->t_to_sleep = ft_atoi(av[4]);
	info->nb_each_ph_eat = ac == 6 ? ft_atoi(av[5]) : -1;
}

t_philo			*create_t_philo_array(pthread_mutex_t *mutex,
int *nb_ph_fed, t_pdata *ph_die, t_info *info)
{
	t_philo	*ph;
	int		nb_ph;
	long	time_start;

	nb_ph = info->nb_ph;
	if (!(ph = malloc(sizeof(*ph) * (nb_ph + 1))))
		return (NULL);
	ph[nb_ph].id = 0;
	time_start = get_time_ms();
	while (nb_ph - 1 >= 0)
	{
		ph[nb_ph - 1].id = nb_ph;
		ph[nb_ph - 1].time_start = time_start;
		ph[nb_ph - 1].mutex = mutex;
		ph[nb_ph - 1].info = info;
		ph[nb_ph - 1].ph_die = ph_die;
		ph[nb_ph - 1].nb_ph_fed = nb_ph_fed;
		nb_ph--;
	}
	return (ph);
}
