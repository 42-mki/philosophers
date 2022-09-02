/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:19:27 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 19:15:45 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		main(int ac, char **av)
{
	t_philo			ph;
	t_info			info;

	if (check_arguments(ac, av))
		return (FAILURE);
	init_t_info(&info, ac, av);
	if (info.nb_ph < 2)
		return (error_msg("Not enough philosphers, must be at least 2\n"));
	create_t_philo_array(&ph, &info);
	launch_processes(&ph);
	clean_exit(ph);
	return (0);
}
