/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putul_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:18:28 by vegret            #+#    #+#             */
/*   Updated: 2022/11/14 16:31:24 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define HEXVALS "0123456789abcdef"
#define UPPERHEXVALS "0123456789ABCDEF"

int	hexlen(unsigned long n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	putul_hex_aux(unsigned long n, int u)
{
	if (n < 16)
	{
		if (u)
			return (write(1, &UPPERHEXVALS[n], 1));
		return (write(1, &HEXVALS[n], 1));
	}
	return (putul_hex_aux(n / 16, u) + putul_hex_aux(n % 16, u));
}

int	putul_hex(unsigned long n, int u, t_flag *flag)
{
	int	printed;
	int	nextlen;

	printed = 0;
	if (!(flag && flag->flags & ZERO))
	{
		nextlen = hexlen(n);
		if (flag && flag->flags & DOT && flag->precision > nextlen)
			nextlen = flag->precision;
		nextlen += 2 * (flag && flag->flags & SHARP && n > 0);
		printed = fill_before(flag, nextlen);
	}
	if (flag && flag->flags & SHARP && n > 0)
	{
		if (u)
			printed += write(1, "0X", 2);
		else
			printed += write(1, "0x", 2);
	}
	printed += putzeros(flag, hexlen(n), printed);
	if (n < 16)
		printed += putul_hex_aux(n, u);
	else
		printed += putul_hex_aux(n / 16, u) + putul_hex_aux(n % 16, u);
	return (printed);
}
