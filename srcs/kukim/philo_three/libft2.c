/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kukim <kukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:54:19 by kukim             #+#    #+#             */
/*   Updated: 2021/01/19 19:15:43 by kukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	better_sleep(long d)
{
	struct timeval	tmp;
	struct timeval	start;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(50);
		gettimeofday(&tmp, NULL);
		if ((((long)(tmp.tv_sec - start.tv_sec)) * 1000000
		+ ((long)(tmp.tv_usec - start.tv_usec))) >= d)
			return ;
	}
}

int		lennb_for_str(unsigned int nb)
{
	int len;

	len = 1;
	while (nb > 9)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int		lennb(unsigned int nb)
{
	int len;

	len = 1;
	while (nb > 9)
	{
		len *= 10;
		nb /= 10;
	}
	return (len);
}

void	ft_putnbr_buffer(int n, char *str)
{
	unsigned int	temp;
	unsigned int	len;
	char			carac;

	carac = '-';
	temp = n;
	if (n < 0)
	{
		*str = carac;
		str++;
		temp = -n;
	}
	len = lennb(temp);
	while (len >= 10)
	{
		*str = temp / len + 48;
		str++;
		temp %= len;
		len /= 10;
	}
	*str = temp + 48;
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	if (src == NULL)
		return (0);
	while (src[len])
		len++;
	if (dstsize == 0)
		return (len);
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
