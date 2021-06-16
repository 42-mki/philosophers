/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:08:53 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 17:17:49 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	check_philo_is_fed(t_philo *ph, int *nb_of_time_ph_ate)
{
	sem_wait(ph->printing);
	if (++(*nb_of_time_ph_ate) == ph->info->nb_each_ph_eat)
	{
		if (++(*(ph->nb_ph_fed)) == ph->info->nb_ph)
		{
			if (!(*(ph->ph_die)))
				ft_putstr_fd("All philosphers have eaten enough\n", 1);
			*(ph->ph_die) = 1;
		}
	}
	sem_post(ph->printing);
}

void	philo_eat(t_philo *ph, int *nb_of_time_ph_ate)
{
	sem_wait(ph->nb_forks);
	print_state_msg(ph, ph->id, get_time_ms() - ph->time_start, FORK);
	print_state_msg(ph, ph->id, get_time_ms() - ph->time_start, FORK);
	ph->time_last_meal = get_time_ms();
	print_state_msg(ph, ph->id, get_time_ms() - ph->time_start, EAT);
	check_philo_is_fed(ph, nb_of_time_ph_ate);
	better_sleep(ph->info->t_to_eat * 1000);
	sem_post(ph->nb_forks);
	print_state_msg(ph, ph->id, get_time_ms() - ph->time_start, SLEEP);
	better_sleep(ph->info->t_to_sleep * 1000);
	print_state_msg(ph, ph->id, get_time_ms() - ph->time_start, THINK);
}

void	*check_philo_alive(void *tmp)
{
	t_philo		*ph;
	long		time_death;

	ph = (t_philo *)tmp;
	while (1)
	{
		time_death = get_time_ms();
		if ((time_death - ph->time_last_meal) > ph->info->t_to_die)
		{
			sem_wait(ph->printing);
			if (!(*(ph->ph_die)))
				print_ms_and_state(ph->id, time_death
				- ph->time_start, " has died\n");
			*(ph->ph_die) = 1;
			sem_post(ph->printing);
			return (NULL);
		}
		if (*(ph->ph_die))
			return (NULL);
	}
}

void	*philo_life(void *ph)
{
	pthread_t	control_die;
	int			nb_of_time_ph_ate;

	nb_of_time_ph_ate = 0;
	((t_philo *)ph)->time_last_meal = get_time_ms();
	pthread_create(&control_die, NULL, &check_philo_alive, ph);
	while (1)
	{
		philo_eat((t_philo *)ph, &nb_of_time_ph_ate);
		if (*(((t_philo *)ph)->ph_die))
		{
			pthread_join(control_die, NULL);
			return (ph);
		}
	}
	return (ph);
}
