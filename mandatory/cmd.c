/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:38:19 by tokerman          #+#    #+#             */
/*   Updated: 2022/10/24 05:16:24 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_cmd(t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd;
	char	*full_cmd;

	dup2(pipex->tube[1], STDOUT_FILENO);
	close(pipex->tube[0]);
	dup2(pipex->file_in, STDIN_FILENO);
	cmd = ft_split(argv[2], ' ');
	full_cmd = get_full_cmd(pipex->env_paths, cmd[0]);
	if (!full_cmd)
	{
		write(2, "zsh: command not found: ", 24);
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, "\n", 1);
		free_spl(cmd);
		free_pipex(pipex);
		exit(1);
	}
	execve(full_cmd, cmd, envp);
	free_spl(cmd);
	free(full_cmd);
}

void	second_cmd(t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd;
	char	*full_cmd;

	dup2(pipex->tube[0], STDIN_FILENO);
	close(pipex->tube[1]);
	dup2(pipex->file_out, STDOUT_FILENO);
	cmd = smart_split(argv[3]);
	full_cmd = get_full_cmd(pipex->env_paths, cmd[0]);
	if (!full_cmd)
	{
		write(2, "zsh: command not found: ", 24);
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, "\n", 1);
		free_spl(cmd);
		free_pipex(pipex);
		exit(1);
	}
	execve(full_cmd, cmd, envp);
	free_spl(cmd);
	free(full_cmd);
}
