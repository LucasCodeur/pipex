/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:43:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/07 11:45:02 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>

// TODO 

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*path;
	char	**commands;
	int		i;
	
	if (argc == 0 || argc > 5)
		return (1);
	i = 0;
	// int	fd_3 = open(argv[1], O_CREAT | O_WRONLY, 0644); 
	// if (data.fd[0] == -1)
	// {
	// 	return (1);
	// }
	int	fd_4 = open(argv[4], O_CREAT | O_WRONLY, 0644); 
	if (data.fd[1] == -1)
	{
		return (1);
	}
	if (pipe(data.fd) == -1)
		return (1);
	data.path_bins = get_path_bins(envp);
	if (!data.path_bins)
		return (1);
	data.pid_1 = fork();
	if (data.pid_1 < 0)
		return (2);
	if (data.pid_1 == 0)
	{
		if (dup2(data.fd[1], STDOUT_FILENO) == -1)
		{
			return (1);
		}
		close(data.fd[1]);
		while (1)
		{
			commands = malloc(ft_strlen(argv[2]) * sizeof(char *));
			if (!commands)
				return (1);
			commands = ft_split(argv[2], ' ');
			path = ft_strjoin(data.path_bins[i], "/");
			if (!path[i])
				return (1);
			path = ft_strjoin(path, commands[0]);
			if (!path[i])
				return (1);
			// break ;
			if (!data.path)
			{
				free(data.path_bins);
				return (1);
			}
			if (access(path, F_OK) == -1)
			{
				free(path);
				i++;
			}
			else
				execve(path, commands, envp);
		}
	}
	else
	{
		if (dup2(data.fd[0], STDIN_FILENO) == -1 || dup2(fd_4, STDOUT_FILENO) == -1)
		{
			return (1);
		}
		close(data.fd[0]);
		while (1)
		{
			commands = malloc(ft_strlen(argv[3]) * sizeof(char *));
			if (!commands)
				return (1);
			commands = ft_split(argv[3], ' ');
			path = ft_strjoin(data.path_bins[i], "/");
			if (!path[i])
				return (1);
			path = ft_strjoin(path, commands[0]);
			ft_printf("Commands :%s", commands[0]);
			if (!path[i])
				return (1);
			// break ;
			if (!data.path)
			{
				free(data.path_bins);
				return (1);
			}
			if (access(path, F_OK) == -1)
			{
				free(path);
				i++;
			}
			else
				execve(path, commands, envp);
		}
	}
	waitpid(data.pid_1, NULL, 0);
	return (0);
}
