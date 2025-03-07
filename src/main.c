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

// TODO 
// int execve(const char *pathname, char *const argv[], char *const envp[]);

int	main(int argc, char **argv, char **envp)
{

	t_data	data;
	char	*path;
	int		i;
	
	if (argc == 1 || argc > 5)
		return (1);
	i = 0;
	data.path_bins = get_path_bins(envp);
	if (pipe(data.fd) == -1)
		return (1);
	data.pid_1 = fork();
	if (data.pid_1 < 0)
		return (2);
	if (data.pid_1 == 0)
	{
		dup2(data.fd[1], STDOUT_FILENO);
		close(data.fd[0]);
		close(data.fd[1]);
		while (data.path_bins)
		{
			path = ft_strjoin(data.path_bins[i], argv[1]);
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
				execve(path, argv, envp);
		}
	}
	data.pid_2 = fork();
	if (data.pid_2 == 0)
	{
		dup2(data.fd[0], STDIN_FILENO);
		close(data.fd[0]);
		close(data.fd[1]);
		while (data.path_bins)
		{
			path = ft_strjoin(data.path_bins[i], argv[1]);
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
				execve(path, argv, envp);
		}
	}
	waitpid(data.pid_1, NULL, 0);
	waitpid(data.pid_2, NULL, 0);
	return (0);
}
