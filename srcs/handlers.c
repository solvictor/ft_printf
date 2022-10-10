/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:20:23 by vegret            #+#    #+#             */
/*   Updated: 2022/10/10 19:35:23 by vegret           ###   ########.fr       */
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

static int	handle_flags(const char **s, t_flag **flag)
{
	int	i;

	*flag = NULL;
	if (**s != '-' && **s != '0')
		return (0);
	i = 0;
	*flag = malloc(sizeof(t_flag));
	(*flag)->type = **s;
	(*flag)->value = ft_atoi(*s + 1, &i);
	*s += i + 1;
	return (i + 1);
}

int	handle_conv(const char *s, int *i, va_list args, t_flag **flag)
{
	*i += handle_flags(&s, flag);
	if (*s == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*s == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*s == 'p')
		return (putptr(va_arg(args, void *)));
	if (*s == 'd' || *s == 'i')
		return (putint(va_arg(args, int), *flag));
	if (*s == 'u')
		return (putui(va_arg(args, unsigned int), *flag));
	if (*s == 'x' || *s == 'X')
		return (putul_hex(va_arg(args, unsigned int), *s == 'X', *flag));
	if (*s == '%')
		return (ft_putchar('%'));
	return (-1);
}
