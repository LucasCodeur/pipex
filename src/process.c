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

#include "pipex.h"

void	first_child(t_data *data, char *envp[], char *argv[])
{
	int	fd_3;

	fd_3 = open(argv[1], O_CREAT | O_RDONLY, 0644); 
	if (fd_3 == -1)
		exit(EXIT_FAILURE);
	data->i = 0;
	data->pid_1 = fork();
	if (data->pid_1 < 0)
		exit(EXIT_FAILURE);
	if (data->pid_1 == 0)
	{
		if (dup2(fd_3, STDIN_FILENO) == -1) 
		{
			exit(EXIT_FAILURE);
		}
		if (dup2(data->fd[1], STDOUT_FILENO) == -1)
		{
			exit(EXIT_FAILURE);
		}
		close(data->fd[1]);
		exec_command(data, envp, argv[2]);
	}
	close(fd_3);
}

void	last_child(t_data *data, char *envp[], char *argv[])
{
	int	fd_4;
	close(data->fd[0]);
	close(data->fd[1]);
	data->buf[data->end] = '\0';
	ft_putstr_fd(data->buf, data->fd_2[1]);
	close(data->fd_2[1]);
	data->i = 0;
	fd_4 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	data->pid_2 = fork();

	if (data->pid_2 == 0)
	{
		if (dup2(data->fd_2[0], STDIN_FILENO) == -1)
		{
			exit(EXIT_FAILURE);
		}
		close(data->fd_2[0]);
		if (dup2(fd_4, STDOUT_FILENO) == -1)
		{
			exit(EXIT_FAILURE);
		}
		exec_command(data, envp, argv[3]);
	}
	close(fd_4);
}
