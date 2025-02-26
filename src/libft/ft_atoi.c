/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveil <eveil@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:35:40 by lud-adam          #+#    #+#             */
/*   Updated: 2024/11/26 10:29:32 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (TRUE);
	return (FALSE);
}

t_bool	ft_is_plus_or_minus(int c)
{
	if (c == '-' || c == '+')
		return (TRUE);
	return (FALSE);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;
	long	old_value;

	result = 0;
	sign = 1;
	while (ft_isspace(*nptr) == TRUE)
		nptr++;
	if (ft_is_plus_or_minus(*nptr) == TRUE)
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr) == 1 && *nptr != '\0')
	{
		old_value = result;
		result = result * 10 + (*nptr - 48);
		if (old_value > result && sign == 1)
			return (-1);
		else if (old_value > result && sign == -1)
			return (0);
		nptr++;
	}
	return ((int)result * sign);
}
