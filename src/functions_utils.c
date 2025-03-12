/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:19:13 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/11 19:10:46 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*str_two_join(char *str, char *str_2, char *str_3)
{
	char	*temp_str;
	char	*final_str;

	if (!str || !str_2 || !str_3)
		return (NULL);
	temp_str = ft_strjoin(str, str_2);
	if (!temp_str)
		return (NULL);
	final_str = ft_strjoin(temp_str, str_3);
	free(temp_str);
	if (!final_str)
		return (NULL);
	return (final_str);
}

char	**free_double_array(char **strs)
{
	size_t	i;

	i = 0;
	if (!strs)
		return (NULL);
	while (strs[i])
	{
		if (strs[i])
			free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

size_t	nb_lines(char **strs)
{
	size_t	i;

	i = 0;
	if (!strs)
		return (0);
	while (strs[i])
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
