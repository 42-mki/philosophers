/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:54:35 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 17:07:35 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	join_all_threads(t_philo *ph)
{
	int		i;

	i = -1;
	while (ph[++i].id)
		pthread_join(ph[i].thread, NULL);
}

void	clean_exit(t_philo *ph)
{
	int		i;

	i = -1;
	while (ph[++i].id)
		pthread_mutex_destroy(&((ph[i].mutex)[i]));
	pthread_mutex_destroy(&(ph->ph_die->mutex));
	free(ph->mutex);
	free(ph);
}
