/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:38:19 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/18 16:56:24 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	first_cmd(t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd;
	char	*full_cmd;

	dup2(pipex->tube[1], 1);
	close(pipex->tube[0]);
	dup2(pipex->file_in, 0);
	cmd = ft_split(argv[2], ' ');
	full_cmd = get_full_cmd(pipex->env_paths, cmd[0]);
	if (!full_cmd)
	{
		free_spl(cmd);
		error_msg("Command not found\n");
	}
	execve(full_cmd, cmd, envp);
	free_spl(cmd);
	free(full_cmd);
}

void	second_cmd(t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd;
	char	*full_cmd;

	close(pipex->tube[1]);
	dup2(pipex->file_out, 1);
	dup2(pipex->tube[0], 0);
	cmd = ft_split(argv[3], ' ');
	full_cmd = get_full_cmd(pipex->env_paths, cmd[0]);
	if (!full_cmd)
	{
		free_spl(cmd);
		error_msg("Command not found\n");
	}
	execve(full_cmd, cmd, envp);
	free_spl(cmd);
	free(full_cmd);
}
