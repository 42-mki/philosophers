/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 03:05:14 by mki               #+#    #+#             */
/*   Updated: 2020/10/17 20:30:46 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dst;

	if (src == 0 && dst == 0)
		return (NULL);
	tmp_dst = dst;
	i = 0;
	while (i < n)
	{
		tmp_dst[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
