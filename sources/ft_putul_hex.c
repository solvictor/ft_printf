/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putul_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:18:28 by vegret            #+#    #+#             */
/*   Updated: 2022/11/11 16:30:34 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define HEXVALS "0123456789abcdef"
#define UPPERHEXVALS "0123456789ABCDEF"

/*static int	hexlen(unsigned long n)
{
	int	len;

	len = 1;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}*/

static int	putul_hex_aux(unsigned long n, int u)
{
	/*if (flag)
	{
		if (flag->flags & 0b1 && flag->value)
		{
			flag->value--;
			return (ft_putchar('0', NULL) + putul_hex_aux(n, u, flag));
		}
	}*/
	if (n < 16)
	{
		if (u)
			return (ft_putchar(UPPERHEXVALS[n]));
		return (ft_putchar(HEXVALS[n]));
	}
	return (putul_hex_aux(n / 16, u) + putul_hex_aux(n % 16, u));
}

int	putul_hex(unsigned long n, int u)
{
	/*if (flag)
	{
		flag->value -= hexlen(n);
		if (flag->value < 0)
			flag->value = 0;
		if (n && flag->flags & 0b10)
		{
			flag->flags &= 0b11111101;
			if (u)
				return (ft_putstr("0X", NULL) + putul_hex(n, u, flag));
			return (ft_putstr("0x", NULL) + putul_hex(n, u, flag));
		}
	}*/
	if (n < 16)
		return (putul_hex_aux(n, u));
	return (putul_hex_aux(n / 16, u) + putul_hex_aux(n % 16, u));
}
