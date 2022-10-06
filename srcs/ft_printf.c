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
#include <ft_printf.h>

unsigned int	(*funcs[2])();

unsigned int	handle_conv(char c, va_list args)
{
	int	i;

	i = 0;
	while (CONVS[i])
	{
		if (CONVS[i] == c)
			return (funcs[i](va_arg(args, double)));
		i++;
	}
	// ERROR
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int				i;
	unsigned int	count;
	va_list			args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += handle_conv(format[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	printf("%d\n", 0x2A);
	return (0);
}
