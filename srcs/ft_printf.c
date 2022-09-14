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
#include "libft.h"

void	handle_conv(char c, va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, char));
	else if (c == 'd')
		ft_putnbr(va_arg(args, int));
	else if (c == '%')
		ft_putchar('%');
	else if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == '')
}

int	ft_printf(const char *str, ...)
{
	int i;
	va_list args;

	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			handle_conv(str[i + 1], args);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return 0;
}
