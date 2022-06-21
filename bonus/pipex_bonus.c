/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:15:46 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/21 12:17:57 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 4)
		return (msg("Invalid number of arguments.\n"));
	pipex.file_in = open(argv[1], O_RDONLY);
	if (pipex.file_in < 0)
		error_msg("Infile");
	pipex.file_out = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.file_out < 0)
		error_msg("Outfile");
	pipex.nb_cmd = argc - 3;
	pipex.nb_pipe = 2 * (pipex.nb_cmd - 1);
	pipex.pipe = ft_calloc(pipex.nb_pipe, sizeof(int));
	if (pipe(pipex.pipe) < 0)
		error_msg("Pipe");
	pipex.env_paths = get_env_paths(envp);
	pipex.icmd = 0;
	while (pipex.icmd < pipex.nb_cmd)
	{
		cmd(&pipex, argv, envp);
		(pipex.icmd)++;
	}
	close_pipe(&pipex);
	waitpid(-1, NULL, 0);
	free_pipex(&pipex);
	return (0);
}
