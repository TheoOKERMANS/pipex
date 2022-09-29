/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:42:29 by tokerman          #+#    #+#             */
/*   Updated: 2022/09/29 18:20:51 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_spl(char **spl)
{
	size_t	i;

	i = 0;
	while (spl && spl[i] != NULL)
		free(spl[i++]);
	free(spl);
}

void	free_pipex(t_pipex *pipex)
{
	int	i;

	close(pipex->file_in);
	close(pipex->file_out);
	if (pipex->here_doc)
		unlink(".here_doc");
	free_spl(pipex->env_paths);
	i = 0;
	while (i < pipex->nb_cmd - 1)
		free(pipex->pipe[i++]);
	free(pipex->pipe);
}
