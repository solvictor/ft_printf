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
#define HEXVALS "0123456789abcdef"
#define UPPERHEXVALS "0123456789ABCDEF"

int	ft_putul_hex(unsigned long n, int upper)
{
	if (n < 16)
	{
		if (upper)
			return (ft_putchar(UPPERHEXVALS[n]));
		return (ft_putchar(HEXVALS[n]));
	}
	return (ft_putul_hex(n / 16, upper) + ft_putul_hex(n % 16, upper));
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n));
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (ft_putnbr(n / 10) + ft_putnbr(n % 10));
}

int	ft_putui(unsigned int n)
{
	if (n < 10)
		return (ft_putchar(n + '0'));
	return (ft_putui(n / 10) + ft_putui(n % 10));
}
