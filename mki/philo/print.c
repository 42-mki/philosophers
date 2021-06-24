/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:04:35 by mki               #+#    #+#             */
/*   Updated: 2021/06/24 21:03:17 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_time_num(int time, int number, char *str)
{
	ft_putstr_fd(ft_itoa(time), 1);
	write(1, " ", 1);
	ft_putstr_fd(ft_itoa(number), 1);
	write(1, " ", 1);
	ft_putstr_fd(str, 1);
}

void	print_state(int time, int number, int state)
{
	if (state == TAKE)
		print_time_num(time, number + 1, "has taken a fork\n");
	else if (state == EAT)
		print_time_num(time, number + 1, "is eating\n");
	else if (state == SLEEP)
		print_time_num(time, number + 1, "is sleeping\n");
	else if (state == THINK)
		print_time_num(time, number + 1, "is thinking\n");
	else if (state == DIE)
		print_time_num(time, number + 1, "died\n");
}
