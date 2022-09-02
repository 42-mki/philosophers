/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:18:40 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 19:15:53 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	join_all_threads(t_philo *ph)
{
	int		i;

	i = -1;
	while (ph[++i].id)
		pthread_join(ph[i].thread, NULL);
}

void	clean_exit(t_philo ph)
{
	sem_unlink(S_FORKS);
	sem_unlink(S_PRINT);
	sem_unlink(S_TAKE);
	sem_unlink(S_PHILO_DIE);
	sem_unlink(S_NB_PH_FED);
	sem_close(ph.nb_forks);
	sem_close(ph.printing);
	sem_close(ph.take_forks);
	sem_close(ph.ph_die);
	sem_close(ph.nb_ph_fed);
}
