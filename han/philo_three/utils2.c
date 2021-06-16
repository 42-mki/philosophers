/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:25:53 by han               #+#    #+#             */
/*   Updated: 2021/01/19 22:28:43 by han              ###   ########.fr       */
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
	t_info		*info;

	info = get_info();
	sem_wait(info->sem_write);
	sem_wait(info->sem_write_dead);
	ft_putnbr(get_time() - info->start_time);
	write(1, "\t", 1);
	if (type != T_OVER)
		ft_putnbr(philo->index + 1);
	write(1, get_msg(type), ft_strlen(get_msg(type)));
	if (type < T_DIED)
		sem_post(info->sem_write_dead);
	sem_post(info->sem_write);
}

int
	ft_strlcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (i);
}
