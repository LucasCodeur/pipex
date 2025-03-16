/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:32:44 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/07 11:41:56 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *envp[])
{
	int	i;
	
	i = 0;
	while (envp && envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			if (ft_strlen(envp[i]) > 5)
				return (envp[i]);
		i++;
	}
	return (NULL);
}

char	**get_path_bins(char *envp[])
{
	char	*path;
	char	**all_paths_bins;

	path = get_path(envp);
	if (!path)
		exit(EXIT_FAILURE);
	all_paths_bins = ft_split(path, ':');
	if (!all_paths_bins)
	{
		free(path);
		exit(EXIT_FAILURE);
	}
	return (all_paths_bins);
}
