/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:19:48 by mki               #+#    #+#             */
/*   Updated: 2020/10/22 03:13:36 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;
	size_t	index;

	if (!s1)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	ret = (char *)malloc(len_s1++ + len_s2++ + 1);
	if (!ret)
		return (NULL);
	index = 0;
	while (--len_s1)
		ret[index++] = *(s1++);
	while (--len_s2)
		ret[index++] = *(s2++);
	ret[index] = '\0';
	return (ret);
}
