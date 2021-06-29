/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:59:28 by mki               #+#    #+#             */
/*   Updated: 2021/06/22 12:27:35 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_numlen(int n)
{
	size_t	ret;

	if (n > 0)
		ret = 0;
	else if (n < 0)
	{
		ret = 1;
		n *= -1;
	}
	else
		return (1);
	while (n)
	{
		ret++;
		n /= 10;
	}
	return (ret);
}

char			*ft_itoa(int n)
{
	char	*ret;
	size_t	numlen;
	size_t	sign;

	numlen = ft_numlen(n);
	ret = (char *)malloc(sizeof(char) * (numlen + 1));
	if (!ret)
		return (NULL);
	ret[numlen] = '\0';
	sign = 1;
	if (!n)
		ret[0] = '0';
	if (n < 0)
	{
		sign = -1;
		ret[0] = '-';
	}
	while (n)
	{
		ret[--numlen] = (n % 10) * sign + '0';
		n /= 10;
	}
	return (ret);
}
