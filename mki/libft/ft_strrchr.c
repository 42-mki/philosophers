/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:47:27 by mki               #+#    #+#             */
/*   Updated: 2020/10/08 20:20:10 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ret;

	ret = (char *)s;
	len = ft_strlen(ret) + 1;
	ret += len;
	while (len--)
	{
		if (*--ret == (char)c)
			return (ret);
	}
	return (NULL);
}
