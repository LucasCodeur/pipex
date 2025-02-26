/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:14:03 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/13 12:17:10 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *string)
{
	int		sign;
	long	result;
	long	old_value;

	result = 0;
	sign = 1;
	while (ft_isspace(*string) == TRUE)
		string++;
	if (ft_is_plus_or_minus(*string) == TRUE)
	{
		if (*string == '-')
			sign = -1;
		string++;
	}
	while (ft_isdigit(*string) == TRUE && *string != '\0')
	{
		old_value = result;
		result = result * 10 + (*string - 48);
		if (old_value > result && sign == 1)
			return (-1);
		else if (old_value > result && sign == -1)
			return (0);
		string++;
	}
	return (result * sign);
}
