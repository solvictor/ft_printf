/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:17:44 by greentor          #+#    #+#             */
/*   Updated: 2022/10/10 19:35:20 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uintlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putui_aux(unsigned int n, t_flag *flag)
{
	if (flag && flag->type == '0' && flag->value)
	{
		flag->value--;
		return (ft_putchar('0') + ft_putui_aux(n, flag));
	}
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (ft_putui_aux(n / 10, flag) + ft_putui_aux(n % 10, flag));
}

int	ft_putui(unsigned int n, t_flag *flag)
{
	if (flag)
	{
		flag->value -= uintlen(n);
		if (flag->value < 0)
			flag->value = 0;
	}
	if (n < 10)
		return (ft_putui_aux(n, flag));
	return (ft_putui_aux(n / 10, flag) + ft_putui_aux(n % 10, flag));
}
