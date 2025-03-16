/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveil <eveil@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:01:58 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/16 15:06:10 by eveil            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!s)
		return (count);
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static char	**ft_free(char **strs, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*ft_strdupp(const char *s, char c, size_t *i)
{
	char	*dest;
	size_t	len;
	size_t	j;

	len = 0;
	j = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		len++;
		(*i)++;
	}
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (dest);
	*i -= len;
	while (s[*i] != c && s[*i] != '\0')
	{
		dest[j] = s[*i];
		(*i)++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**final_array;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s || s[0] == '\0')
		return (NULL);
	size = count_words(s, c);
	i = 0;
	j = 0;
	final_array = ft_calloc(size + 1, sizeof(char *));
	if (!final_array)
		return (final_array);
	while (j < size && s)
	{
		while (s[i] == c)
			i++;
		final_array[j] = ft_strdupp(s, c, &i);
		if (!final_array[j])
			return (ft_free(final_array, j));
		while (s[i] == c && s[i] != '\0')
			i++;
		j++;
	}
	return (final_array);
}
