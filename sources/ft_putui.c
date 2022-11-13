/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:17:44 by vegret            #+#    #+#             */
/*   Updated: 2022/11/13 18:58:49 by vegret           ###   ########.fr       */
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

static int	putui_aux(unsigned int n)
{
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (putui_aux(n / 10) + putui_aux(n % 10));
}

int	putui(unsigned int n, t_flag *flag)
{
	int	printed;

	printed = putzeros(flag, uintlen(n));
	if (n < 10)
		printed += putui_aux(n);
	else
		printed += putui_aux(n / 10) + putui_aux(n % 10);
	return (printed);
}
