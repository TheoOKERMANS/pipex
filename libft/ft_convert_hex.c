/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:15:04 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/09 15:31:50 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_hex_to_int(char c)
{
	if (c >= 48 && c <= 57)
		return (c - 48);
	if (c >= 65 && c <= 70)
		return (c - 55);
	if (c >= 97 && c <= 102)
		return (c - 87);
	return (-1);
}

int	hex_to_int(char *str)
{
	int	res;
	int	pow;
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 1;
	pow = 1;
	while (i++ < len)
		pow *= 16;
	res = 0;
	i = 0;
	while (str[i])
	{
		res += char_hex_to_int(str[i]) * pow;
		pow /= 16;
		i++;
	}
	return (res);
}
