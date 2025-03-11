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
#include <unistd.h>

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
	char	**differents_path;

	path = get_path(envp);
	differents_path = malloc(sizeof(char *) * count_words(path, ':'));
	if (!differents_path)
		exit(EXIT_FAILURE);
	path = get_path(envp);
	differents_path = ft_split(path, ':');
	if (!differents_path)
		exit(EXIT_FAILURE);
	return (differents_path);
}
