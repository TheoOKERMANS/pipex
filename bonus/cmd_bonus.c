/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:38:19 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/21 12:21:33 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	close_pipe(t_pipex *pipex)
{
	int	i;
	
	i = 0;
	while (i < pipex->nb_pipe)
		close(pipex->pipe[i++]);
}

void	change_pipe(t_pipex *pipex, int in, int out)
{
	dup2(in, 0);
	dup2(out, 1);
	close_pipe(pipex);
}

void	cmd(t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd;
	char	*full_cmd;
	int		pid;

	pid = fork();
	if (!pid)
	{
		if (pipex->icmd == 0 && pipex->nb_cmd == 1)
			change_pipe(pipex, pipex->file_in, pipex->file_out);
		else if (pipex->icmd == 0)
			change_pipe(pipex, pipex->file_in, pipex->pipe[1]);
		else if (pipex->icmd == pipex->nb_cmd - 1)
			change_pipe(pipex, pipex->pipe[pipex->icmd * 2 - 2], pipex->file_out);
		else
			change_pipe(pipex, pipex->pipe[pipex->icmd * 2 - 2], pipex->pipe[pipex->icmd * 2 + 1]);
		cmd = ft_split(argv[pipex->icmd + 2], ' ');
		full_cmd = get_full_cmd(pipex->env_paths, cmd[0]);
		if (!full_cmd)
		{
			free_spl(cmd);
			free_pipex(pipex);
			error_msg("Command not found\n");
		}
		execve(full_cmd, cmd, envp);
		free_spl(cmd);
		free(full_cmd);
	}
}
