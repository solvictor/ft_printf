/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:08:12 by vegret            #+#    #+#             */
/*   Updated: 2022/09/15 01:08:12 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_flag
{
	const char	*type;
	int			value;
}				t_flag;

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr);
int	ft_putnbr(int n);
int	ft_putui(unsigned int n);
int	ft_putul_hex(unsigned long n, int upper);

#endif
