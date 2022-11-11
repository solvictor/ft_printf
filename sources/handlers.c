/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:20:23 by vegret            #+#    #+#             */
/*   Updated: 2022/11/11 23:35:02 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_atoi(const char *s, int *i)
{
	int	r;

	r = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		r = r * 10 + s[*i] - '0';
		(*i)++;
	}
	return (r);
}

static int	strindex(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_pow(int n, int k)
{
	if (k < 0)
		return (0);
	if (k == 0)
		return (1);
	if (k == 1)
		return (n);
	return (n * ft_pow(n, k - 1));
}

static int	handle_flags(const char **s, t_flag *flag)
{
	int	skipped;
	int	index;

	flag->flags = 0;
	flag->minimal_width = 0;
	flag->precision = 0;
	if (strindex(CONVS, **s) != -1)
		return (0);
	index = strindex(FLAGS, **s);
	skipped = 0;
	while (index != -1 && (*s)[skipped])
	{
		flag->flags |= ft_pow(2, index);
		index = strindex(FLAGS, (*s)[++skipped]);
	}
	if (flag->flags & SPACE && flag->flags & PLUS)
		flag->flags &= ~SPACE;
	flag->minimal_width = ft_atoi(*s, &skipped);
	if ((*s)[skipped] == '.')
	{
		skipped++;
		flag->precision = ft_atoi(*s, &skipped);
	}
	*s += skipped;
	return (skipped);
}

int	handle_conv(const char *s, int *i, va_list args, t_flag flag)
{
	int	printed;

	*i += handle_flags(&s, &flag);
	printed = 0;
	if (*s == 'c')
		printed += ft_putchar(va_arg(args, int));
	else if (*s == 's')
		printed += ft_putstr(va_arg(args, char *), 0);
	else if (*s == 'p')
		printed += putptr(va_arg(args, void *));
	else if (*s == 'd' || *s == 'i')
		printed += putint(va_arg(args, int), &flag);
	else if (*s == 'u')
		printed += putui(va_arg(args, unsigned int));
	else if (*s == 'x' || *s == 'X')
		printed += putul_hex(va_arg(args, unsigned int), *s == 'X');
	else if (*s == '%')
		printed += write(1, "%", 1);
	return (printed);
}
