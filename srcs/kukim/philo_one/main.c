/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:54:30 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 16:46:53 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		main(int ac, char **av)
{
	t_info			info;
	int				nb_ph_fed;
	t_pdata			ph_die;
	pthread_mutex_t	*mutex;
	t_philo			*ph;

	if (check_arguments(ac, av))
		return (FAILURE);
	init_t_info(&info, ac, av);
	if (info.nb_ph < 2)
		return (error_msg("Not enough philosphers, must be at least 2\n"));
	nb_ph_fed = 0;
	pthread_mutex_init(&(ph_die.mutex), NULL);
	ph_die.data = 0;
	if (!(mutex = create_forks(info.nb_ph)))
		return (error_msg("Malloc failed\n"));
	if (!(ph = create_t_philo_array(mutex, &nb_ph_fed, &ph_die, &info)))
		return (error_msg("Malloc failed\n"));
	launch_threads(ph);
	join_all_threads(ph);
	clean_exit(ph);
	return (0);
}
