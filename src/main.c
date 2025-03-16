/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveil <eveil@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:43:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/16 15:32:03 by eveil            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	initialize_values(t_data *data)
{
	data->all_paths = NULL;
	data->commands = NULL;
	data->path = NULL;
	data->path_bin = NULL;
}
static void	statements_fds_and_pipe(t_data *data, char *argv[], int argc, char *envp[])
{
		data->fd.outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (data->fd.outfile == -1)
			perror("bash");
		data->fd.infile = open(argv[1], O_CREAT | O_RDONLY, 0644); 
		if (data->fd.infile == -1)
		{
			perror("bash");
			close(data->fd.outfile);
			exit(EXIT_SUCCESS);
		}
		if (pipe(data->fd.first_pipe) == -1)
		{
			perror("Pipe error");
			close_fds(data);
			close(data->fd.outfile);
			close(data->fd.infile);
			exit(EXIT_SUCCESS);
		}
		data->all_paths = get_path_bins(envp);
		if (!data->all_paths)
		{
			close_fds(data);
			exit(EXIT_FAILURE);
		}
}

static void	handle_return_of_status(t_data data, int argc)
{
	if (waitpid(data.pid_1, &data.status, 0) == -1)
		exit(EXIT_FAILURE);
	if (data.status == 127)
		exit(127);
	if (data.status == -1)
		exit(EXIT_FAILURE);
	if (argc > 4 && waitpid(data.pid_2, &data.status, 0) == -1)
		exit(EXIT_FAILURE);
	if (argc > 4 && data.status == -1)
		exit(EXIT_FAILURE);
	if (argc > 4 && data.status == 127)
		exit(127);
	if (WIFEXITED(data.status))
		exit(WEXITSTATUS(data.status));
	else if (WIFSIGNALED(data.status))
	    exit(128 + WTERMSIG(data.status));
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 2 || argc > 5 || !envp)
		return (0);
	initialize_values(&data);
	statements_fds_and_pipe(&data, argv, argc, envp);
	if (argc > 4)
	{
		first_child(&data, envp, argv);
		close(data.fd.first_pipe[1]);
		last_child(&data, envp, argv);
		close(data.fd.first_pipe[0]);
		free_and_close_all(&data);
	}
	else if (argc == 4)
	{
		one_conmmand(&data, envp, argv);
		free_and_close_all(&data);
	}
	handle_return_of_status(data, argc);
	return (0);
}
