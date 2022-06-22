/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:15:46 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/22 15:01:34 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Norminette
Erreur/messages
Free/valgrind
.h clean avec toutes les fonctions
*/

#include "../includes/pipex_bonus.h"

void	here_doc(t_pipex *pipex, char **argv)
{
	int		fd;
	char	*buf;

	fd = open(".here_doc", O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (fd < 0)
		error_msg("here_doc");
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(0);
		if (buf == NULL)
			exit(1);
		if (!ft_strncmp(argv[2], buf, ft_strlen(argv[2])))
			break;
		write(fd, buf, ft_strlen(buf));
		free(buf);
	}
	get_next_line(-1);
	free(buf);
	close(fd);
	pipex->file_in = open(".here_doc", O_RDONLY);
	if (pipex->file_in < 0)
	{
		unlink(".here_doc");
		error_msg("here_doc");
	}
}

void get_file_in(t_pipex *pipex, char **argv)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
	{
		here_doc(pipex, argv);
		pipex->here_doc = 1;
	}
	else
	{
		pipex->file_in = open(argv[1], O_RDONLY);
		if (pipex->file_in < 0)
			error_msg("Infile");
		pipex->here_doc = 0;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int 	i;

	if (argc < 4)
		return (msg("Invalid number of arguments.\n"));
	get_file_in(&pipex, argv);
	pipex.file_out = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.file_out < 0)
		error_msg("Outfile");
	pipex.nb_cmd = argc - 3 - pipex.here_doc;
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
