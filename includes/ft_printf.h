/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greentor <greentor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:08:12 by vegret            #+#    #+#             */
/*   Updated: 2022/10/10 19:25:27 by greentor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flag
{
	char	type;
	int		value;
}				t_flag;

int	ft_printf(const char *format, ...);
int	handle_conv(const char *s, int *i, va_list args, t_flag **flag);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr);
int	ft_putnbr(int n, t_flag *flag);
int	ft_putui(unsigned int n, t_flag *flag);
int	ft_putul_hex(unsigned long n, int upper, t_flag *flag);

#endif
