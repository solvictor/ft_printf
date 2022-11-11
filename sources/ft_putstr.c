/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:00:48 by vegret            #+#    #+#             */
/*   Updated: 2022/11/11 16:34:18 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	printed;

	printed = 0;
	/*if (flag && (flag->flags & 0b10000) && flag->value)
		(flag->value)--;*/
	printed += write(1, &c, 1);
	return (printed /*+ putspaces(flag, 0)*/);
}

int	ft_putstr(char *str, int i)
{
	if (!str)
		return (write(1, "(null)", 6));
	if (str[i])
		return (write(1, &str[i], 1) + ft_putstr(str, i + 1));
	return (0);
}
