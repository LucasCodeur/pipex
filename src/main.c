/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:43:40 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/10 14:59:31 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <unistd.h>

// TODO 

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	
	if (argc == 0 || argc > 5)
		return (1);
	if (pipe(data.fd) == -1)
		return (1);
	data.all_paths = get_path_bins(envp);
	if (!data.all_paths)
		return (1);
	first_child(&data, envp, argv);
	if (pipe(data.fd_2) == -1)
		return (1);
	data.end = read(data.fd[0], &data.buf, 4096);
	last_child(&data, envp, argv);
	close(data.fd_2[0]);
	close(data.fd_2[1]);
	waitpid(data.pid_1, NULL, 0);
	waitpid(data.pid_2, NULL, 0);
	return (0);
}
