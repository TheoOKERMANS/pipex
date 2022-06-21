/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:15:46 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/21 11:18:20 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (msg("Invalid number of arguments.\n"));
	pipex.file_in = open(argv[1], O_RDONLY);
	if (pipex.file_in < 0)
		error_msg("Infile");
	pipex.file_out = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.file_out < 0)
		error_msg("Outfile");
	if (pipe(pipex.tube) < 0)
		error_msg("Pipe");
	pipex.env_paths = get_env_paths(envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_cmd(&pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_cmd(&pipex, argv, envp);
	close(pipex.tube[0]);
	close(pipex.tube[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_pipex(&pipex);
	return (0);
}
