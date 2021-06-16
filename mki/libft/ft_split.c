/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 22:06:33 by mki               #+#    #+#             */
/*   Updated: 2020/10/18 00:27:42 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words_count(char const *s, char c)
{
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	if (s[index] && s[index] != c)
		count++;
	while (s[index])
	{
		if (s[index] == c && s[index + 1] != c && s[index + 1] != '\0')
			count++;
		index++;
	}
	return (count);
}

static size_t	ft_word_length(char const *s, char c)
{
	size_t	index;

	index = 0;
	while (s[index] && s[index] != c)
		index++;
	return (index);
}

static	size_t	ft_isfree(char **ret)
{
	size_t	index;

	index = 0;
	while (ret[index])
		free(ret[index++]);
	free(ret);
	return (1);
}

static size_t	ft_fill(char **ret, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			ret[i] = (char *)malloc(ft_word_length(s, c) + 1);
			if (!ret[i])
				return (ft_isfree(ret));
			while (*s && *s != c)
				ret[i][j++] = (char)*s++;
			ret[i][j] = '\0';
			i++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_words_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ret)
		return (NULL);
	if (ft_fill(ret, s, c))
		return (NULL);
	ret[count] = NULL;
	return (ret);
}
