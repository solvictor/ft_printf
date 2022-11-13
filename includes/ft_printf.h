/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:08:12 by vegret            #+#    #+#             */
/*   Updated: 2022/11/14 00:28:30 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONVS "cspdiuxX%"
# define FLAGS "-0# +"
# define MINUS 0b000001
# define ZERO  0b000010
# define SHARP 0b000100
# define SPACE 0b001000
# define PLUS  0b010000
# define DOT   0b100000

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
6th bit = .
*/
typedef struct s_flag
{
	unsigned char	flags;
	int				minimal_width;
	int				precision;
}				t_flag;

int	ft_printf(const char *format, ...);
int	handle_conv(const char *s, va_list args, t_flag *flag);
int	handle_flags(const char *s, t_flag *flag);
int	ft_putchar(char c);
int	ft_putstr(char *str, int i, t_flag *flag);
int	putptr(void *ptr, t_flag *flag);
int	putint(int n, t_flag *flag);
int	putui(unsigned int n, t_flag *flag);
int	putul_hex(unsigned long n, int upper, t_flag *flag);
int	fill_width(t_flag *flag, int already_printed);
int	putzeros(t_flag *flag, int elen, int already_printed);
int	make_compatibility(int flags);

#endif
