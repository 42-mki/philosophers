/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:04:35 by mki               #+#    #+#             */
/*   Updated: 2021/06/27 19:08:37 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_time_num(t_global *global, int time, int number, char *str)
{
	char	*ret;

	pthread_mutex_lock(&global->mutex_print);
	ret = ft_itoa(time);
	ft_putstr_fd(ret, 1);
	free(ret);
	write(1, " ", 1);
	ret = ft_itoa(number);
	ft_putstr_fd(ret, 1);
	free(ret);
	write(1, " ", 1);
	ft_putstr_fd(str, 1);
	pthread_mutex_unlock(&global->mutex_print);
}

void	print_state(t_global *global, int time, int number, int state)
{
	if (!global->monitor_flag && state == TAKE)
		print_time_num(global, time, number + 1, "has taken a fork\n");
	else if (!global->monitor_flag && state == EAT)
		print_time_num(global, time, number + 1, "is eating\n");
	else if (!global->monitor_flag && state == SLEEP)
		print_time_num(global, time, number + 1, "is sleeping\n");
	else if (!global->monitor_flag && state == THINK)
		print_time_num(global, time, number + 1, "is thinking\n");
	else if (!global->monitor_flag && state == DIE)
		print_time_num(global, time, number + 1, "died\n");
}
