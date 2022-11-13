/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:56:13 by vegret            #+#    #+#             */
/*   Updated: 2022/11/13 23:46:49 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putzeros(t_flag *flag, int elen, int already_printed)
{
	int	printed;

	printed = 0;
	if (flag)
	{
		if (flag->flags & ZERO)
		{
			elen += already_printed;
			while (elen < flag->minimal_width)
			{
				printed += write(1, "0", 1);
				elen++;
			}
		}
		if (flag->flags & DOT)
		{
			while (elen < flag->precision)
			{
				printed += write(1, "0", 1);
				elen++;
			}
		}
	}
	return (printed);
}

int	fill_width(t_flag *flag, int already_printed)
{
	int	printed;

	printed = 0;
	if (flag->flags & MINUS)
	{
		flag->minimal_width -= already_printed;
		while (flag->minimal_width > 0)
		{
			printed += write(1, " ", 1);
			flag->minimal_width--;
		}
	}
	return (printed);
}

int	make_compatibility(int flags)
{
	if (flags & SPACE && flags & PLUS)
		flags &= ~SPACE;
	if (flags & ZERO && flags & MINUS)
		flags &= ~ZERO;
	if (flags & ZERO && flags & DOT)
		flags &= ~ZERO;
	return (flags);
}
