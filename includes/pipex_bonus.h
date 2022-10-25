/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:44:27 by tokerman          #+#    #+#             */
/*   Updated: 2022/10/25 17:03:30 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		file_in;
	int		file_out;
	int		nb_cmd;
	int		icmd;
	int		**pipe;
	char	**env_paths;
	int		here_doc;
}	t_pipex;

//err
void	error_msg(char *msg);
int		msg(char *err);
void	error_open_hd(void);
void	error_cmd_not_found(char *cmd);

//cmd
void	close_pipe(t_pipex *pipex, int in, int out);
int		cmd(t_pipex *pipex, char **argv, char **envp);

//path
char	**get_env_paths(char **envp);
char	*get_full_cmd(char **env_paths, char *cmd);
char	**get_executable_spl(t_pipex *pipex, char **argv, char *full_cmd);

//free
void	free_spl(char **spl);
void	free_pipex(t_pipex *pipex);

#endif