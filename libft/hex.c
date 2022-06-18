/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:42:30 by tokerman          #+#    #+#             */
/*   Updated: 2022/05/31 17:21:21 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlong_fd(long n, int fd)
{
	int	res;

	res = 1;
	if (n > 9)
	{
		res += ft_putlong_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + 48, fd);
	return (res);
}

int	printf_adress(va_list *param)
{
	unsigned long long	adr;
	void				*p;

	p = va_arg(*param, void *);
	adr = (unsigned long long)p;
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		return (2 + printf_hexa_lowcase_ll(adr));
	}
}

int	printf_hexa_lowcase(unsigned int i)
{
	int	res;

	res = 1;
	if (i > 15)
		res += printf_hexa_lowcase(i / 16);
	i = i % 16;
	if (i <= 9)
		ft_putchar_fd(i + 48, 1);
	else
		ft_putchar_fd(i + 87, 1);
	return (res);
}

int	printf_hexa_lowcase_ll(unsigned long long i)
{
	int	res;

	res = 1;
	if (i > 15)
		res += printf_hexa_lowcase_ll(i / 16);
	i = i % 16;
	if (i <= 9)
		ft_putchar_fd(i + 48, 1);
	else
		ft_putchar_fd(i + 87, 1);
	return (res);
}

int	printf_hexa_upcase(unsigned int i)
{
	int	res;

	res = 1;
	if (i > 15)
		res += printf_hexa_upcase(i / 16);
	i = i % 16;
	if (i <= 9)
		ft_putchar_fd(i + 48, 1);
	else
		ft_putchar_fd(i + 55, 1);
	return (res);
}
