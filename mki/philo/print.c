/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:04:35 by mki               #+#    #+#             */
/*   Updated: 2021/06/25 16:31:30 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_time_num(pthread_mutex_t *mutex, int time, int number, char *str)
{
	pthread_mutex_lock(mutex);
	ft_putstr_fd(ft_itoa(time), 1);
	write(1, " ", 1);
	ft_putstr_fd(ft_itoa(number), 1);
	write(1, " ", 1);
	ft_putstr_fd(str, 1);
	pthread_mutex_unlock(mutex);
}

void	print_state(pthread_mutex_t *mutex, int time, int number, int state)
{
	if (state == TAKE)
		print_time_num(mutex, time, number + 1, "has taken a fork\n");
	else if (state == EAT)
		print_time_num(mutex, time, number + 1, "is eating\n");
	else if (state == SLEEP)
		print_time_num(mutex, time, number + 1, "is sleeping\n");
	else if (state == THINK)
		print_time_num(mutex, time, number + 1, "is thinking\n");
	else if (state == DIE)
		print_time_num(mutex, time, number + 1, "died\n");
}
