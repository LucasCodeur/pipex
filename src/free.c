/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:02:16 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/14 18:14:23 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_and_close_all(t_data *data)
{
	if (data->all_paths)
		free_double_array(data->all_paths);
	if (data->commands)
		free_double_array(data->commands);
	if (data->path)
		free(data->path);
	if (data->path_bin)
		free(data->path_bin);
	if (data->fd.first_pipe[0] != -1)
		close(data->fd.first_pipe[0]);
	if (data->fd.first_pipe[1] != -1)
		close(data->fd.first_pipe[1]);
	if (data->fd.infile != -1)
		close(data->fd.infile);
	if (data->fd.outfile != -1)
		close(data->fd.outfile);
}
