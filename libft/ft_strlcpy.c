/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 22:02:11 by mki               #+#    #+#             */
/*   Updated: 2020/10/18 00:21:36 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize)
{
	size_t	len;

	if (!dst && !src)
		return (0);
	len = 0;
	while (src[len])
		len++;
	if (!dstsize)
		return (len);
	while (*src && --dstsize)
		*(dst++) = *(src++);
	*dst = '\0';
	return (len);
}
