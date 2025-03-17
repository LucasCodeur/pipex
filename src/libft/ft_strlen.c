/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveil <eveil@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:54:45 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/17 14:34:16 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlen_improve(const char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c)
		i++;
	return (i);
}

size_t	ft_strlen_choose_way_and_c(char *str, char c, t_bool start_or_end)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!str)
		return (0);
	if (start_or_end == TRUE)
	{
		while (str[k] != c && str[k])
			k++;
		return (k);
	}
	i = ft_strlen(str);
	if (start_or_end == FALSE)
	{
		j = i - 1;
		i--;
		while (str[i] != c)
			i--;
		return (j - i);
	}
	return (0);
}
