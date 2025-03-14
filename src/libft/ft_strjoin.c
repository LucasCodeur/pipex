/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:17:17 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/11 18:21:17 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s_s1;
	size_t	s_s2;
	char	*final_array;

	if (!s1 || !s2)
		return (NULL);
	s_s1 = ft_strlen(s1);
	s_s2 = ft_strlen(s2);
	final_array = malloc((s_s1 + s_s2 + 1) * sizeof(char));
	if (!final_array)
		return (final_array);
	ft_memcpy(final_array, s1, s_s1);
	ft_memcpy(&final_array[s_s1], s2, s_s2);
	final_array[s_s1 + s_s2] = '\0';
	return (final_array);
}
