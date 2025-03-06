/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:32:44 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/05 15:55:55 by lud-adam         ###   ########.fr       */
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
			break ;
		i++;
	}
	return (envp[i]);
}

char	**get_path_bins(char *envp[])
{
	char	*path;
	char	**differents_path;

	path = get_path(envp);
	differents_path = malloc(sizeof(char *) * count_words(path, ':'));
	if (!differents_path)
		exit(EXIT_FAILURE);
	if (path)
		differents_path = ft_split(path, ':');
	else
		exit(EXIT_FAILURE);
	int		i;

	i = 0;
	while (differents_path[++i])
		ft_printf("%s\n", differents_path[i]);
	return (differents_path);
}
//
// char	*get_accurate_path(char **differents_path)
// {
// 	char	*accurate_path;
// 	size_t	i;
//
// 	i = 0;
// 	while (differents_path[i])
// 	{
//
// 	}
//
// }
