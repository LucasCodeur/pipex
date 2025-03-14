/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:25:47 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/10 14:23:11 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf/ft_printf.h"
#include "pipex.h"

void	first_child(t_data *data, char *envp[], char *argv[])
{
	data->pid_1 = fork();
	if (data->pid_1 < 0)
	{
		free_and_close_all(data);
		perror("Error pid_1");
		exit(EXIT_SUCCESS);
	}
	if (data->pid_1 == 0)
	{
		if (dup2(data->fd.infile, STDIN_FILENO) == -1) 
		{
			free_and_close_all(data);
			perror("Error dup2");
			exit(EXIT_FAILURE);
		}
		if (dup2(data->fd.first_pipe[1], STDOUT_FILENO) == -1)
		{
			free_and_close_all(data);
			perror("Error dup2");
			exit(EXIT_FAILURE);
		}
		close(data->fd.first_pipe[0]);
		exec_command(data, envp, argv[2]);
	}
	close(data->fd.infile);
}

void	last_child(t_data *data, char *envp[], char *argv[])
{
	data->pid_2 = fork();
	if (data->pid_2 == 0)
	{
		if (dup2(data->fd.first_pipe[0], STDIN_FILENO) == -1)
		{
			free_and_close_all(data);
			perror("Error dup2");
			exit(EXIT_FAILURE);
		}
		if (dup2(data->fd.outfile, STDOUT_FILENO) == -1)
		{
			free_and_close_all(data);
			perror("Error dup2");
			exit(EXIT_FAILURE);
		}
		close(data->fd.first_pipe[1]);
		exec_command(data, envp, argv[3]);
	}
	close(data->fd.outfile);
}
