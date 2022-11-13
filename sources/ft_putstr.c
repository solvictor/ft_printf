/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:00:48 by vegret            #+#    #+#             */
/*   Updated: 2022/11/13 22:23:02 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str, int i, t_flag *flag)
{
	if (!str)
		return (write(1, "(null)", 6));
	if (flag && flag->flags & DOT && i >= flag->precision)
		return (0);
	if (str[i])
		return (write(1, &str[i], 1) + ft_putstr(str, i + 1, flag));
	return (0);
}
