/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:14:40 by vegret            #+#    #+#             */
/*   Updated: 2022/11/09 19:29:59 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;
	t_flag	**flag;

	i = 0;
	count = 0;
	flag = malloc(sizeof(t_flag *));
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_conv(format + i, &i, args, flag);
			if (*flag)
				free(*flag);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	free(flag);
	return (count);
}

/*int main()
{
	ft_printf("%d\n", -2147483648);
	return 0;
}*/
