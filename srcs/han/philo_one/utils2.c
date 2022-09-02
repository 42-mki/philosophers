/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:41:51 by han               #+#    #+#             */
/*   Updated: 2021/01/19 19:54:23 by han              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char
	*get_msg(int type)
{
	if (type == T_EAT)
		return (" is eating\n");
	else if (type == T_SLEEP)
		return (" is sleeping\n");
	else if (type == T_FORK)
		return (" has taken a fork\n");
	else if (type == T_THINK)
		return (" is thinking\n");
	else if (type == T_OVER)
		return ("must eat count reached\n");
	return (" died\n");
}

void
	dp_msg(t_philo *philo, int type)
{
	static int	done = 0;
	t_info		*info;

	info = get_info();
	pthread_mutex_lock(&info->mt_write);
	if (!done)
	{
		ft_putnbr(get_time() - info->start_time);
		write(1, "\t", 1);
		if (type != T_OVER)
			ft_putnbr(philo->index + 1);
		if (type >= T_DIED)
			done = 1;
		write(1, get_msg(type), ft_strlen(get_msg(type)));
	}
	pthread_mutex_unlock(&info->mt_write);
}
