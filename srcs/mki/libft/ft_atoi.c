/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 22:06:33 by mki               #+#    #+#             */
/*   Updated: 2020/10/18 00:25:20 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

int	ft_atoi(const char *str)
{
	long long	ret;
	int			sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (ft_isdigit(*str))
	{
		ret *= 10;
		ret += (*str - '0') * sign;
		if (ret > 2147483647)
			return (-1);
		else if (ret < -2147483648)
			return (0);
		str++;
	}
	return (ret);
}
