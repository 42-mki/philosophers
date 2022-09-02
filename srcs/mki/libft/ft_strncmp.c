/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:50:14 by mki               #+#    #+#             */
/*   Updated: 2020/10/08 21:57:50 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 <= len_s2)
		len = len_s1 + 1;
	else
		len = len_s2 + 1;
	if (n <= len)
		len = n;
	return (ft_memcmp(s1, s2, len));
}
