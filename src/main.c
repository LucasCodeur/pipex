/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:43:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/14 13:48:54 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <unistd.h>

// TODO 

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc > 5 || !envp)
		return (1);

	data.fd.outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data.fd.outfile == -1)
		perror("bash");
	data.fd.infile = open(argv[1], O_CREAT | O_RDONLY, 0644); 
	if (data.fd.infile == -1)
	{
		perror("bash");
		exit(EXIT_SUCCESS);
	}
	if (pipe(data.fd.first_pipe) == -1)
	{
		perror("Pipe error");
		return (1);
	}
	data.all_paths = get_path_bins(envp);
	if (!data.all_paths)
		return (1);
	first_child(&data, envp, argv);
	close(data.fd.first_pipe[1]);
	last_child(&data, envp, argv);
	close(data.fd.first_pipe[0]);
	free_double_array(data.all_paths);
	if (waitpid(data.pid_1, &data.status, 0) == -1)
		exit(EXIT_FAILURE);
	if (data.status == 127)
		exit(127);
	if (data.status == -1)
		exit(EXIT_FAILURE);
	if (waitpid(data.pid_2, &data.status, 0) == -1)
		exit(EXIT_FAILURE);
	if (data.status == -1)
		exit(EXIT_FAILURE);
	if (data.status == 127)
		exit(127);
	if (WIFEXITED(data.status))
		 exit(WEXITSTATUS(data.status));
	else if (WIFSIGNALED(data.status))
	        exit(128 + WTERMSIG(data.status));
	return (0);
}
