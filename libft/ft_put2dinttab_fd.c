/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2dinttab_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:31:12 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/21 15:58:08 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put2dinttab_fd(int **tab, size_t h, size_t w, int fd)
{
	size_t	i;

	i = 0;
	while (tab && i < h)
	{
		ft_putinttab_fd(tab[i], w, fd);
		i++;
	}
}