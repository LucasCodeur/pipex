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

#include "pipex.h"

void	exec_command(t_data *data, char *envp[], char *command)
{
	while (data->all_paths[data->i])
	{
		data->commands = malloc(ft_strlen(command) * sizeof(char *));
		if (!data->commands)
			exit(EXIT_FAILURE);
		data->commands = ft_split(command, ' ');
		data->path_bin = ft_strjoin(data->all_paths[data->i], "/");
		if (!data->path_bin[data->i])
			exit(EXIT_FAILURE);
		data->path_bin = ft_strjoin(data->path_bin, data->commands[0]);
		if (!data->path_bin[data->i])
			exit(EXIT_FAILURE);
		if (access(data->path_bin, F_OK) == -1)
		{
			free(data->path_bin);
			data->i++;
		}
		else
			execve(data->path_bin, data->commands, envp);
	}
}
