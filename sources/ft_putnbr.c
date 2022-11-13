/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:30:40 by vegret            #+#    #+#             */
/*   Updated: 2022/11/13 21:31:56 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	putint_aux(int n)
{
	if (n == -2147483648)
		return (ft_putstr("2147483648", 0, NULL));
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (putint_aux(n / 10) + putint_aux(n % 10));
}

int	putint(int n, t_flag *flag)
{
	int	printed;

	printed = 0;
	if (n < 0)
		printed = write(1, "-", 1) + putzeros(flag, intlen(n)) + putint_aux(-n);
	else
	{
		if (flag->flags & SPACE)
			printed += write(1, " ", 1);
		if (flag->flags & PLUS)
			printed += write(1, "+", 1);
		printed += putzeros(flag, printed + intlen(n)) + putint_aux(n);
	}
	return (printed);
}
