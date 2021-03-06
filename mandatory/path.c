/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:40:53 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/21 11:18:22 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_env_paths(char **envp)
{
	size_t	i;

	i = 0;
	while (envp && envp[i] != NULL)
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

char	*get_full_cmd(char **env_paths, char *cmd)
{
	char	*path;
	char	*full_cmd;

	while (env_paths && *env_paths != NULL)
	{
		path = ft_strjoin(*env_paths, "/");
		full_cmd = ft_strjoin(path, cmd);
		free(path);
		if (access(full_cmd, 0) == 0)
			return (full_cmd);
		free(full_cmd);
		env_paths++;
	}
	return (NULL);
}
