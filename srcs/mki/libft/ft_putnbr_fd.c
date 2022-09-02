/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:48:06 by mki               #+#    #+#             */
/*   Updated: 2020/10/12 22:33:26 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	tmp;
	char		c;

	if (fd < 0)
		return ;
	tmp = (long long)n;
	if (tmp < 0)
	{
		write(fd, "-", 1);
		tmp *= -1;
	}
	c = tmp % 10 + '0';
	if (tmp > 9)
		ft_putnbr_fd(tmp / 10, fd);
	write(fd, &c, 1);
}
