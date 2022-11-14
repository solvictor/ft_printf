/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:00:48 by vegret            #+#    #+#             */
/*   Updated: 2022/11/14 14:08:19 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_c(char c, t_flag *flag)
{
	return (fill_before(flag, 1) + write(1, &c, 1));
}

static int	nstrlen(char *str, t_flag *flag)
{
	int	len;

	if (!str)
		return (6);
	len = 0;
	while (str[len])
		len++;
	if (flag && flag->flags & DOT && len > flag->precision)
		len = flag->precision;
	return (len);
}

int	putstr(char *str, t_flag *flag)
{
	int	printed;
	int	i;

	printed = fill_before(flag, nstrlen(str, flag));
	if (!str)
		printed += (write(1, "(null)", 6));
	else
	{
		i = 0;
		while (str[i])
		{
			if (flag && flag->flags & DOT && i >= flag->precision)
				return (printed);
			printed += write(1, &str[i], 1);
			i++;
		}
	}
	return (printed);
}
