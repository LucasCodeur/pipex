/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:50:55 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/10 09:33:14 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
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

typedef struct s_fd
{
	int		first_pipe[2];
	int		last_pipe[2];
	int		infile;
	int		outfile;

}	s_fd;

typedef struct s_data
{
	s_fd	fd;
	size_t	i;
	int		pid_1;
	int		pid_2;
	char	*path_bin;
	char	*path;
	char	**commands;
	char	**all_paths;
	char	buf[4096];
	int		end;
}	t_data;


char	*get_path(char *envp[]);
char	**get_path_bins(char *envp[]);
void	last_child(t_data *data, char *envp[], char *argv[]);
void	first_child(t_data *data, char *envp[], char *argv[]);
void	exec_command(t_data *data, char *envp[], char *command);

#endif
