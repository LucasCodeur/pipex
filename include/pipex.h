/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:50:55 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/05 15:57:52 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> 
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include "../src/libft/libft.h"

// TODO TAKE OFF
	# include <stdio.h>

typedef struct s_data
{
	int		pid_1;
	int		pid_2;
	int		fd[2];
	int		fd_2[2];
	char	**path_bins;
	char	*path;
}	t_data;

// PARSING ENVP
char	*get_path(char *envp[]);
char	**get_path_bins(char *envp[]);


#endif
