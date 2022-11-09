/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:30:40 by vegret            #+#    #+#             */
/*   Updated: 2022/11/09 21:11:52 by vegret           ###   ########.fr       */
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
		if (flag->flags & 0b1 && flag->value)
		{
			flag->value--;
			return (ft_putchar('0') + putint_aux(n, flag));
		}
	}
	if (n == -2147483648)
		return (ft_putstr("2147483648"));
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (putint_aux(n / 10, flag) + putint_aux(n % 10, flag));
}

static int	putspacesbefore(t_flag *flag, int pos)
{
	if (flag && (flag->flags & 0b100 || flag->flags & 0b1000) && flag->value)
	{
		if (flag->flags & 0b1000 && flag->value == 1 && pos)
			return (ft_putchar('+'));
		flag->value--;
		return (ft_putchar(' ') + putspacesbefore(flag, pos));
	}
	return (0);
}

int	putint(int n, t_flag *flag)
{
	if (flag)
	{
		flag->value -= intlen(n);
		if (flag->value < 0)
			flag->value = 0;
		if (flag->value == 0 && (flag->flags & 0b100 || flag->flags & 0b1000))
			flag->value = 1 - (n < 0);
	}
	if (n < 0)
		return (putspacesbefore(flag, 0) + ft_putchar('-') + putint_aux(-n, flag));
	return (putspacesbefore(flag, 1) + putint_aux(n, flag));
}
