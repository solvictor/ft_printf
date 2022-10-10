/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:08:12 by vegret            #+#    #+#             */
/*   Updated: 2022/10/10 19:25:27 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flag
{
	char	type;
	int		value;
}				t_flag;

int	ft_printf(const char *format, ...);
int	handle_conv(const char *s, int *i, va_list args, t_flag **flag);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	putptr(void *ptr);
int	putint(int n, t_flag *flag);
int	putui(unsigned int n, t_flag *flag);
int	putul_hex(unsigned long n, int upper, t_flag *flag);

#endif
