/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:09:00 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 17:12:17 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		main(int ac, char **av)
{
	t_philo			*ph;
	t_info			info;
	int				ph_die;
	int				nb_ph_fed;

	if (check_arguments(ac, av))
		return (FAILURE);
	ph_die = 0;
	nb_ph_fed = 0;
	init_t_info(&info, ac, av);
	if (info.nb_ph < 2)
		return (error_msg("Not enough philosphers, must be at least 2\n"));
	if (!(ph = create_t_philo_array(&info, &nb_ph_fed, &ph_die)))
		return (error_msg("Malloc failed\n"));
	launch_threads(ph);
	join_all_threads(ph);
	clean_exit(ph);
	return (0);
}
