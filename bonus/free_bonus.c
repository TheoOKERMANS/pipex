/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:42:29 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/21 11:19:17 by tokerman         ###   ########.fr       */
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
	close(pipex->file_in);
	close(pipex->file_out);
	free_spl(pipex->env_paths);
}