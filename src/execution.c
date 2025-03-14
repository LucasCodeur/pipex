/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:31:36 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/12 18:12:01 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>

char	*get_command_with_path(t_data *data, char *command)
{	
	data->i = 0;
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
	char	*temp;

	pathname = command;
	final_command = NULL;
	temp = NULL;
	if (access(pathname, X_OK) == -1)
	{
		pathname = get_command_with_path(data, command);
		if (!pathname)
			exit(EXIT_FAILURE);
		if (execve(pathname, data->commands, envp) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		final_command = malloc(sizeof(char *) * 3);
		temp = ft_strrchr(command, '/') + 1;
		final_command[1] = ft_strdup(temp);
		final_command[2] = NULL;
		if (!final_command)
			exit(EXIT_FAILURE);
		if (execve(pathname, &final_command[1], envp) == -1)
		{
			perror("execve error");
			free_double_array(final_command);
			exit(EXIT_FAILURE);
		}
	}
}
