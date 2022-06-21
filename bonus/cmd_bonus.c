/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:38:19 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/21 16:21:20 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	close_pipe(t_pipex *pipex, int in, int out)
{
	int	i;
	
	i = 0;
	while (i < pipex->nb_cmd - 1)
	{
		if (pipex->pipe[i][0] != in && pipex->pipe[i][0] != out)
			close(pipex->pipe[i][0]);
		if (pipex->pipe[i][1] != in && pipex->pipe[i][1] != out)
			close(pipex->pipe[i][1]);
		i++;
	}
}

void	change_pipe(t_pipex *pipex, int in, int out)
{
	close_pipe(pipex, in, out);
	dup2(in, 0);
	dup2(out, 1);
}

int	*get_pipe(t_pipex *pipex)
{
	static int		pipe[2];
	
	if (pipex->icmd == 0 && pipex->nb_cmd == 1)
	{
		pipe[0] = pipex->file_in;
		pipe[1] = pipex->file_out;
	}
	else if (pipex->icmd == 0)
	{
		pipe[0] = pipex->file_in;
		pipe[1] = pipex->pipe[pipex->icmd][1];
	}
	else if (pipex->icmd == pipex->nb_cmd - 1)
	{
		pipe[0] = pipex->pipe[pipex->icmd - 1][0];
		pipe[1] = pipex->file_out;
	}
	else
	{
		pipe[0] = pipex->pipe[pipex->icmd - 1][0];
		pipe[1] = pipex->pipe[pipex->icmd][1];
	}
	return (pipe);	
}

int	cmd(t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd;
	char	*full_cmd;
	int		pid;
	int		*pipe;

	pid = fork();
	if (pid == 0)
	{
		cmd = ft_split(argv[pipex->icmd + 2], ' ');
		full_cmd = get_full_cmd(pipex->env_paths, cmd[0]);
		pipe = get_pipe(pipex);
		change_pipe(pipex, pipe[0], pipe[1]);		
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
	return(pid);
}
