/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:38:19 by tokerman          #+#    #+#             */
/*   Updated: 2022/10/25 17:03:16 by tokerman         ###   ########.fr       */
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

void	change_pipe(t_pipex *pipex)
{
	int	*pipe;

	pipe = get_pipe(pipex);
	close_pipe(pipex, pipe[0], pipe[1]);
	dup2(pipe[0], 0);
	dup2(pipe[1], 1);
}

void	exec_file(t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd;
	char	*full_cmd;

	cmd = smart_split(argv[pipex->icmd + 2 + pipex->here_doc]);
	execve(cmd[0], cmd, envp);
	full_cmd = get_full_cmd(pipex->env_paths, cmd[0]);
	free_spl(cmd);
	cmd = get_executable_spl(pipex, argv, full_cmd);
	execve(cmd[0], cmd, envp);
	free_spl(cmd);
	free(full_cmd);
	exit(1);
}

int	cmd(t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd;
	char	*full_cmd;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (argv[pipex->icmd + 2 + pipex->here_doc][0] == '.'
			&& argv[pipex->icmd + 2 + pipex->here_doc][1] == '/')
			exec_file(pipex, argv, envp);
		cmd = smart_split(argv[pipex->icmd + 2 + pipex->here_doc]);
		full_cmd = get_full_cmd(pipex->env_paths, cmd[0]);
		change_pipe(pipex);
		if (!full_cmd)
		{
			error_cmd_not_found(cmd[0]);
			free_spl(cmd);
			free_pipex(pipex);
			exit(1);
		}
		execve(full_cmd, cmd, envp);
		free_spl(cmd);
		free(full_cmd);
	}
	return (pid);
}
