/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveil <eveil@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:31:36 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/16 15:15:15 by eveil            ###   ########lyon.fr   */
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
			return (NULL);
		data->path_bin = str_two_join(data->all_paths[data->i], "/", data->commands[0]);
		if (!data->path_bin)
		{
			free_and_close_all(data);
			exit(EXIT_FAILURE);
		}
		if (access(data->path_bin, X_OK) == -1)
		{
			free(data->path_bin);
			data->i++;
		}
		else
		{
			return (data->path_bin);
		}
		free_double_array(data->commands);
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
		{
			free_and_close_all(data);
			exit(127);
		}
		if (execve(pathname, data->commands, envp) == -1)
		{
			free_and_close_all(data);
			perror("execve error");
			exit(EXIT_FAILURE);
		}
		free(pathname);
		free_and_close_all(data);
	}
	else
	{
		final_command = malloc(sizeof(char *) * 3);
		temp = ft_strrchr(command, '/') + 1;
		final_command[1] = ft_strdup(temp);
		final_command[2] = NULL;
		if (!final_command)
		{
			free_and_close_all(data);
			exit(EXIT_FAILURE);
		}
		free_double_array(data->commands); // Free the allocated memory
		if (execve(pathname, &final_command[1], envp) == -1)
		{
			free_double_array(final_command);
			free_and_close_all(data);
			perror("execve error");
			exit(EXIT_FAILURE);
		}
		free_double_array(final_command);
	}

}
