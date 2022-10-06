/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:30:40 by vegret            #+#    #+#             */
/*   Updated: 2022/10/06 20:30:40 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TODO Check
unsigned int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n));
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (ft_putnbr(n / 10) + ft_putnbr(n % 10));
}
