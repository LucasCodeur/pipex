/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam <marvin@42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:54:45 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/24 18:26:58 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!*str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlen_improve(const char *str, char c)
{
	size_t	i;

	i = 0;
	if (!*str)
		return (0);
	while (str[i] != c)
		i++;
	return (i);
}
