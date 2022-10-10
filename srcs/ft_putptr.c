/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:44:33 by vegret            #+#    #+#             */
/*   Updated: 2022/10/10 19:35:16 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	putptr(void *ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + putul_hex((unsigned long) ptr, 0, NULL));
}
