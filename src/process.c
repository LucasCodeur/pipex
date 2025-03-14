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
	data->fd.infile = open(argv[1], O_CREAT | O_RDONLY, 0644); 
	if (data->fd.infile == -1)
	{
		perror("Error open");
		exit(EXIT_FAILURE);
	}
	data->pid_1 = fork();
	if (data->pid_1 < 0)
	{
		perror("Error pid_1");
		exit(EXIT_FAILURE);
	}
	if (data->pid_1 == 0)
	{
		if (dup2(data->fd.infile, STDIN_FILENO) == -1) 
		{
			perror("Error dup2");
			exit(EXIT_FAILURE);
		}
		if (dup2(data->fd.first_pipe[1], STDOUT_FILENO) == -1)
		{
			perror("Error dup2");
			exit(EXIT_FAILURE);
		}
		close(data->fd.first_pipe[1]);
		exec_command(data, envp, argv[2]);
	}
	close(data->fd.infile);
}

void	last_child(t_data *data, char *envp[], char *argv[])
{
	close(data->fd.first_pipe[0]);
	close(data->fd.first_pipe[1]);
	if (ft_putstr_fd(data->buf, data->fd.last_pipe[1]) == -1)
	{
		perror("Write error");
		exit(EXIT_FAILURE);
	}
	close(data->fd.last_pipe[1]);
	data->fd.outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	data->pid_2 = fork();
	if (data->pid_2 == 0)
	{
		if (dup2(data->fd.last_pipe[0], STDIN_FILENO) == -1)
		{
			perror("Error dup2");
			exit(EXIT_FAILURE);
		}
		close(data->fd.last_pipe[0]);
		if (dup2(data->fd.outfile, STDOUT_FILENO) == -1)
		{
			perror("Error dup2");
			exit(EXIT_FAILURE);
		}
		exec_command(data, envp, argv[3]);
	}
	close(data->fd.outfile);
}
