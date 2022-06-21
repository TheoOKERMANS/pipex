/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinttab_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:57:20 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/21 15:35:10 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putinttab_fd(int *tab, size_t size, int fd)
{
	char 	*str;
	size_t	i;

	i = 0;
	while (tab && i < size)
	{
		str = ft_itoa(tab[i]);
		ft_putstr_fd(str, fd);
		ft_putchar_fd(' ', fd);
		free(str);
		i++;
	}
	ft_putchar_fd('\n', fd);
}