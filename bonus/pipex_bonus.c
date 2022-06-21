/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:15:46 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/21 16:38:02 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Norminette
Makefile
Erreur
Free/valgrind


*/


#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int i;

	if (argc < 4)
		return (msg("Invalid number of arguments.\n"));
	pipex.file_in = open(argv[1], O_RDONLY);
	if (pipex.file_in < 0)
		error_msg("Infile");
	pipex.file_out = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.file_out < 0)
		error_msg("Outfile");
	pipex.nb_cmd = argc - 3;
	pipex.pipe = ft_calloc(pipex.nb_cmd, sizeof(int *));
	i = 0;
	while (i < pipex.nb_cmd - 1)
	{
		pipex.pipe[i] = ft_calloc(2, sizeof(int));
		if (pipe(pipex.pipe[i]) < 0)
			error_msg("Pipe");
		i++;
	}
	pipex.env_paths = get_env_paths(envp);
	pipex.icmd = 0;
	while (pipex.icmd < pipex.nb_cmd)
	{
		cmd(&pipex, argv, envp);
		(pipex.icmd)++;
	}
	close_pipe(&pipex, -1, -1);
	waitpid(-1, NULL, 0);
	close(pipex.file_in);
	close(pipex.file_out);
	free_pipex(&pipex);
	return (0);
}
