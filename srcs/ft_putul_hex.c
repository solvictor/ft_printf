/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putul_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:18:28 by greentor          #+#    #+#             */
/*   Updated: 2022/10/10 19:35:21 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define HEXVALS "0123456789abcdef"
#define UPPERHEXVALS "0123456789ABCDEF"

static int	hexlen(unsigned long n)
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

static int	putul_hex_aux(unsigned long n, int u, t_flag *flag)
{
	if (flag && flag->type == '0' && flag->value)
	{
		flag->value--;
		return (ft_putchar('0') + putul_hex_aux(n, u, flag));
	}
	if (n < 16)
	{
		if (u)
			return (ft_putchar(UPPERHEXVALS[n]));
		return (ft_putchar(HEXVALS[n]));
	}
	return (putul_hex_aux(n / 16, u, flag) + putul_hex_aux(n % 16, u, flag));
}

int	putul_hex(unsigned long n, int u, t_flag *flag)
{
	if (flag)
	{
		flag->value -= hexlen(n);
		if (flag->value < 0)
			flag->value = 0;
	}
	if (n < 16)
		return (putul_hex_aux(n, u, flag));
	return (putul_hex_aux(n / 16, u, flag) + putul_hex_aux(n % 16, u, flag));
}
