/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:17:44 by vegret            #+#    #+#             */
/*   Updated: 2022/11/11 23:32:58 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	uintlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}*/

static int	putui_aux(unsigned int n)
{
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (putui_aux(n / 10) + putui_aux(n % 10));
}

int	putui(unsigned int n)
{
	if (n < 10)
		return (putui_aux(n));
	return (putui_aux(n / 10) + putui_aux(n % 10));
}
