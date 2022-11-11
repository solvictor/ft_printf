/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:30:40 by vegret            #+#    #+#             */
/*   Updated: 2022/11/11 17:36:56 by vegret           ###   ########.fr       */
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

static int	putint_aux(int n, t_flag *flag)
{
	if (flag)
	{
		if (flag->flags & 0b1 && flag->minimal_width)
		{
			flag->minimal_width--;
			return (write(1, "0", 1) + putint_aux(n, flag));
		}
	}
	if (n == -2147483648)
		return (ft_putstr("2147483648", 0));
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (putint_aux(n / 10, flag) + putint_aux(n % 10, flag));
}

int	right_justify(int spaces, int n)
{
	if (spaces < 0)
		return (0);
	return (write(1, " ", 1) + right_justify(--spaces, n));
}

int	putint(int n, t_flag flag)
{
	int	printed;

	printed = right_justify(flag.minimal_width - intlen(n), n);
	if (n < 0)
		printed += write(1, "-", 1) + putint_aux(-n, NULL);
	else
		printed += putint_aux(n, NULL);
	return (printed);
}
