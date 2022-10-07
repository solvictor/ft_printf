/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:14:40 by vegret            #+#    #+#             */
/*   Updated: 2022/09/14 17:14:40 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int	handle_conv(const char *c, va_list args)
{
	if (*c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (*c == 'd' || *c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (*c == 'u')
		return (ft_putui(va_arg(args, unsigned int)));
	if (*c == 'x' || *c == 'X')
		return (ft_putul_hex(va_arg(args, unsigned int), *c == 'X'));
	if (*c == '%')
		return (ft_putchar('%'));
	// ERROR
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			count += handle_conv(format + i, args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
