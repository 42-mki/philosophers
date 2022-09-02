/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: han <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:40:27 by han               #+#    #+#             */
/*   Updated: 2021/01/19 22:20:59 by han              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

sem_t
	*ft_sem_open(char const *name, int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

char
	*make_semaphore_name(char const *base, char *buffer, int position)
{
	int	i;

	i = ft_strlcpy(buffer, base);
	while (position > 0)
	{
		buffer[i++] = (position % 10) + '0';
		position /= 10;
	}
	buffer[i] = 0;
	return (buffer);
}
