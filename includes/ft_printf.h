/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:08:12 by vegret            #+#    #+#             */
/*   Updated: 2022/11/11 23:14:47 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONVS "cspdiuxX%"
# define FLAGS "-0# +"
# define MINUS 0b1
# define ZERO  0b10
# define SHARP 0b100
# define SPACE 0b1000
# define PLUS  0b10000

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

/* flags:
1st bit = -
2nd bit = 0
3th bit = #
4th bit = space
5th bit = +
*/
typedef struct s_flag
{
	unsigned char	flags;
	int				minimal_width;
	int				precision;
}				t_flag;

int	ft_printf(const char *format, ...);
int	handle_conv(const char *s, int *i, va_list args, t_flag flag);
int	ft_putchar(char c);
int	ft_putstr(char *str, int i);
int	putptr(void *ptr);
int	putint(int n, t_flag *flag);
int	putui(unsigned int n);
int	putul_hex(unsigned long n, int upper);
int	putspaces(t_flag *flag, int pos);

#endif
