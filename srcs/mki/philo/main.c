/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:58:36 by mki               #+#    #+#             */
/*   Updated: 2021/06/14 11:25:09 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** argv[1] = number_of_philosophers
** argv[2] = time_to_die
** argv[3] = time_to_eat
** argv[4] = time_to_sleep
** argv[5] = [number_of_times_each_philosopher_must_eat]
*/

int	main(int argc, char *argv[])
{
	t_var	var;

	if (argc != 5 && argc != 6)
		ft_putstr_fd("Wrong input\n", 1);
	else
	{
		var.num_of_philos = ft_atoi(argv[1]);
		var.time_to_die = ft_atoi(argv[2]);
		var.time_to_eat = ft_atoi(argv[3]);
		var.time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			var.time_must_eat = ft_atoi(argv[5]);
		if (philo(&var))
			return (0);
	}
	system("leaks philo");
	return (0);
}
