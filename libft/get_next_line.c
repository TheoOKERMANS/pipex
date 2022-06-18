/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:50:20 by tokerman          #+#    #+#             */
/*   Updated: 2022/05/31 17:27:41 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(char *save)
{
	char	*res;
	size_t	len;

	if (save == NULL)
		return (NULL);
	len = 0;
	while (save[len] != '\n' && save[len] != '\0')
		len++;
	if (save[len] == '\n')
		len++;
	if (len == 0)
		return (NULL);
	res = ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	len = 0;
	while (save[len] != '\n' && save[len] != '\0')
	{
		res[len] = save[len];
		len++;
	}
	if (save[len] == '\n')
		res[len] = save[len];
	return (res);
}

char	*get_save(char *save)
{
	char	*res;
	size_t	len;
	size_t	end;

	len = 0;
	while (save[len] != '\n' && save[len] != '\0')
		len++;
	if (save[len] == '\0')
	{
		free(save);
		return (NULL);
	}
	end = len;
	while (save[++end] != '\0')
		;
	res = ft_calloc(end - len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	end = 0;
	len++;
	while (save[len] != '\0')
		res[end++] = save[len++];
	free(save);
	return (res);
}

char	*get_str_from_file(int fd, char *save)
{
	int		read_res;
	char	*buf;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	read_res = 1;
	while (backline_in_str(save) == 0 && read_res > 0)
	{
		read_res = read(fd, buf, BUFFER_SIZE);
		if (read_res == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_res] = '\0';
		save = ft_strjoin_gnl(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = get_str_from_file(fd, save);
	if (save == NULL)
		return (NULL);
	line = get_line(save);
	save = get_save(save);
	return (line);
}
