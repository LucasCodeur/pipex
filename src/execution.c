/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:31:36 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/10 13:55:19 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdlib.h>

char	*get_command_with_path(t_data *data, char *command)
{	
	while (data->all_paths[data->i])
	{
		data->commands = ft_split(command, ' ');
		if (!data->commands)
			exit(EXIT_FAILURE);
		data->path_bin = str_two_join(data->all_paths[data->i], "/", data->commands[0]);
		if (!data->path_bin)
			exit(EXIT_FAILURE);
		if (access(data->path_bin, X_OK) == -1)
		{
			free(data->path_bin);
			data->i++;
		}
		else
			return (data->path_bin);
	}
	return (NULL);
}

void	exec_command(t_data *data, char *envp[], char *command)
{
	char	*pathname;
	char	**final_command;

	pathname = command;
	final_command = NULL;
	if (access(pathname, X_OK) == -1)
	{
		pathname = get_command_with_path(data, command);
		if (!pathname)
			exit(EXIT_FAILURE);
		execve(pathname, data->commands, envp);
	}
	else
	{
		final_command = ft_split(command, '/');
		if (!final_command)
			exit(EXIT_FAILURE);
		execve(pathname, &final_command[nb_lines(final_command) - 1], envp);
	}
}
