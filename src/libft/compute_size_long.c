/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_size_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:37:20 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/12 14:38:48 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compute_size_long(long n)
{
	long long	temp;
	int			size;

	size = 0;
	temp = (long long)n;
	if (n == 0)
		return (size + 1);
	if (n < 0)
	{
		temp = -temp;
		size++;
	}
	while (temp > 0)
	{
		temp /= 10;
		size++;
	}
	return (size);
}
