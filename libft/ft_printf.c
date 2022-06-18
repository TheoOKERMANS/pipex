/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:43:01 by tokerman          #+#    #+#             */
/*   Updated: 2022/05/31 17:21:15 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_string(va_list *param)
{
	char	*str;

	str = (char *)va_arg(*param, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
}

int	printf_char(va_list *param)
{
	ft_putchar_fd(va_arg(*param, int), 1);
	return (1);
}

int	printf_int(va_list *param)
{
	int		val;
	char	*str;

	val = va_arg(*param, int);
	ft_putnbr_fd(val, 1);
	str = ft_itoa(val);
	val = ft_strlen(str);
	free(str);
	return (val);
}

int	conversion_manager(char c, va_list *param)
{
	if (c == 'c')
		return (printf_char(param));
	if (c == 's')
		return (printf_string(param));
	if (c == 'p')
		return (printf_adress(param));
	if (c == 'd')
		return (printf_int(param));
	if (c == 'i')
		return (printf_int(param));
	if (c == 'u')
		return (ft_putlong_fd(va_arg(*param, unsigned int), 1));
	if (c == 'x')
		return (printf_hexa_lowcase(va_arg(*param, unsigned int)));
	if (c == 'X')
		return (printf_hexa_upcase(va_arg(*param, unsigned int)));
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	int		res;

	res = 0;
	va_start(param, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str++, 1);
			res++;
			continue ;
		}
		str++;
		res += conversion_manager(*str, &param);
		str++;
	}
	va_end(param);
	return (res);
}
