/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:44:33 by vegret            #+#    #+#             */
/*   Updated: 2022/11/14 00:28:18 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptr(void *ptr, t_flag *flag)
{
	int	printed;

	printed = 0;
	if (!ptr)
	{
		printed += write(1, "(nil)", 5);
		return (printed);
	}
	printed += write(1, "0x", 2) + putul_hex((unsigned long) ptr, 0, flag);
	return (printed);
}
