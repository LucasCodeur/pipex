/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:43:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/12 18:02:07 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <unistd.h>

// TODO 

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc == 0 || argc > 5 || !envp)
		return (1);
	if (pipe(data.fd.first_pipe) == -1)
	{
		perror("Pipe error");
		return (1);
	}
	data.all_paths = get_path_bins(envp);
	if (!data.all_paths)
		return (1);
	first_child(&data, envp, argv);
	if (pipe(data.fd.last_pipe) == -1)
	{
		perror("Pipe error");
		return (1);
	}
	data.end = read(data.fd.first_pipe[0], &data.buf, 4096);
	if (data.end == -1)
	{
		perror("Read error");
		return (1);
	}
	data.buf[data.end] = '\0';
	last_child(&data, envp, argv);
	close(data.fd.last_pipe[0]);
	close(data.fd.last_pipe[1]);
	if (waitpid(data.pid_1, &data.status, 0) == -1)
		exit(EXIT_FAILURE);
	if (waitpid(data.pid_2, &data.status, 0) == -1)
		exit(EXIT_FAILURE);
	free_double_array(data.all_paths);
	return (0);
}
