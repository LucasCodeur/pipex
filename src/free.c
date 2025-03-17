/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveil <eveil@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:02:16 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/17 16:53:16 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_and_close_all(t_data *data)
{
	if (!data)
		return ;
	if (data->all_paths)
	{
		free_double_array(data->all_paths);
		data->all_paths = NULL;
	}
	if (data->path)
	{
		free(data->path);
		data->path = NULL;
	}
}
