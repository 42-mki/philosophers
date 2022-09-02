/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 22:29:17 by mki               #+#    #+#             */
/*   Updated: 2020/10/11 21:18:28 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	len;

	if (count && size)
	{
		len = count * size;
		if (len % size != 0 || len / size != count)
			return (NULL);
	}
	else
		len = 1;
	ret = (void *)malloc(len);
	if (!ret)
		return (NULL);
	return (ft_memset(ret, 0, len));
}
