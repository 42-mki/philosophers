/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:03:55 by mki               #+#    #+#             */
/*   Updated: 2021/06/22 12:25:52 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

long	get_cur_mili_time(struct timeval tp)
{
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

void	my_usleep(int wait_time)
{
	struct timeval	tp;
	long			obj_time;

	gettimeofday(&tp, NULL);
	obj_time = wait_time + get_cur_mili_time(tp);
	while (obj_time > get_cur_mili_time(tp))
	{
		gettimeofday(&tp, NULL);
		usleep(100);
	}
}

int		main(void)
{
	struct timeval	tp;
	long			start_time;
	
	gettimeofday(&tp, NULL);
	start_time = get_cur_mili_time(tp);
	while (1)
	{
		gettimeofday(&tp, NULL);
		printf("time: %lu\n", get_cur_mili_time(tp) - start_time);
		my_usleep(1000);
	}
	return (0);
}
