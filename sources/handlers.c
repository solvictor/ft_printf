/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:20:23 by vegret            #+#    #+#             */
/*   Updated: 2022/11/09 21:26:18 by vegret           ###   ########.fr       */
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
	if (k == 0)
		return (1);
	if (k == 1)
		return (n);
	return (n * ft_pow(n, k - 1));
}

static int	handle_flags(const char **s, t_flag **flag)
{
	int	skipped;
	int	index;

	*flag = NULL;
	index = strindex(FLAGS, **s);
	if (index == -1)
		return (0);
	skipped = 0;
	*flag = malloc(sizeof(t_flag));
	if (!*flag)
		return (0); // Pas sur a verif
	(*flag)->flags = ft_pow(2, index);
	if (**s == ' ' && **s == '+')
		(*flag)->flags &= 0b11111011;
	(*flag)->value = ft_atoi(*s + 1, &skipped);
	*s += skipped + 1;
	return (skipped + 1);
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
