/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:29:11 by han               #+#    #+#             */
/*   Updated: 2021/01/19 18:48:41 by han              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info
	*get_info(void)
{
	static t_info	info;

	return (&info);
}

int
	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int
	ft_atoi(const char *str)
{
	int		i;
	int		positive;
	int		val;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	positive = str[i] == '-' ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	val = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		val = (val * 10) + (str[i++] - '0');
	return (positive * val);
}

void
	ft_putnbr(int n)
{
	char	str[13];
	int		length;

	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + (n % 10);
		n = (n / 10);
	}
	if (length > 0)
		length--;
	while (length >= 0)
		write(1, &str[length--], 1);
}

unsigned long
	get_time(void)
{
	static struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		write(1, "Error : Failed to get time\n"
			, ft_strlen("Error : Failed to get time\n"));
		return (0);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
