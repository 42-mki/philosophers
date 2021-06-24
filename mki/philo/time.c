/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:31:33 by mki               #+#    #+#             */
/*   Updated: 2021/06/24 13:39:35 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>

/*
** tv.tv_sec * 1000 -> milisec
** tv.tv_usec / 1000 -> milisec
*/

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	my_usleep(int wait_mili_time)
{
	long	obj_time;

	obj_time = wait_mili_time + get_time();
	while (obj_time > get_time())
		usleep(100);
}
