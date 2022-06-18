/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:50:23 by tokerman          #+#    #+#             */
/*   Updated: 2022/05/31 17:27:36 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	backline_in_str(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (1);
			str++;
		}
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	size;
	char	*res;

	size = 0;
	size += ft_strlen(s1);
	size += ft_strlen(s2);
	res = ft_calloc(size + 1, sizeof(char));
	size = 0;
	if (s1)
	{
		while (s1[size])
		{
			res[size] = s1[size];
			size++;
		}
	}
	if (s2)
	{
		while (*s2)
		{
			res[size++] = *s2++;
		}
	}
	free(s1);
	return (res);
}
