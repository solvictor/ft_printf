/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:30:40 by vegret            #+#    #+#             */
/*   Updated: 2022/10/10 19:35:15 by vegret           ###   ########.fr       */
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

// TODO Fix flag 0 && min int
static int	putint_aux(int n, t_flag *flag)
{
	if (flag && flag->type == '0' && flag->value)
	{
		flag->value--;
		return (ft_putchar('0') + putint_aux(n, flag));
	}
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
		return (ft_putchar('-') + putint_aux(-n, flag));
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (putint_aux(n / 10, flag) + putint_aux(n % 10, flag));
}

int	putint(int n, t_flag *flag)
{
	if (flag)
	{
		flag->value -= intlen(n);
		if (flag->value < 0)
			flag->value = 0;
	}
	if (n < 0 && n != -2147483648)
		return (ft_putchar('-') + putint_aux(-n, flag));
	return (putint_aux(n, flag));
}
