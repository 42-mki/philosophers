/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:40:03 by mki               #+#    #+#             */
/*   Updated: 2021/06/24 21:48:56 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	taken_fork(t_global *global, int fork_num, int philo_num)
{
	pthread_mutex_lock(&global->mutex_id[fork_num]);
	global->fork[fork_num] = philo_num;
	print_state(global->base_time - get_time(), philo_num + 1, TAKE);
}

void	return_fork(t_global *global, int fork_num)
{
	global->fork[fork_num] = -1;
	pthread_mutex_unlock(&global->mutex_id[fork_num]);
}
