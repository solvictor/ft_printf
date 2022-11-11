/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:44:33 by vegret            #+#    #+#             */
/*   Updated: 2022/11/11 16:26:21 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptr(void *ptr)
{
	int	printed;

	printed = 0;
	if (!ptr)
	{
		printed += write(1, "(nil)", 5);
		/*if (flag && (flag->flags & 0b10000) && flag->value)
			flag->value -= printed;
		if (flag && (flag->flags & 0b10000) && flag->value < 0)
			flag->value = 0;*/
		return (printed /*+ putspaces(flag, 0)*/);
	}
	printed += write(1, "0x", 2) + putul_hex((unsigned long) ptr, 0);
	/*if (flag && (flag->flags & 0b10000) && flag->value)
		flag->value -= printed;
	if (flag && (flag->flags & 0b10000) && flag->value < 0)
		flag->value = 0;*/
	return (printed /*+ putspaces(flag, 0)*/);
}
