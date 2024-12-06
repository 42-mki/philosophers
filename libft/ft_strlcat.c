/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 02:34:57 by mki               #+#    #+#             */
/*   Updated: 2020/10/17 20:59:12 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strncat(char *dst, const char *src, size_t nb)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (dst[j])
		j++;
	i = 0;
	while (src[i] && i < nb)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = 0;
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (len_dst < dstsize)
	{
		ft_strncat(dst, src, dstsize - 1 - len_dst);
		return (len_src + len_dst);
	}
	else
		return (len_src + dstsize);
}
