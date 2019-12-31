/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:38:16 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 14:56:38 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conversion	get_conversion(const char *str, t_conversion conv, va_list ap)
{
	int i;

	conv.flag = 'v';
	conv.width = 0;
	conv.precision = -1;
	i = get_wid(str, &conv, ap, 1);
	get_pre(str, &conv, ap, i);
	return (conv);
}

int				get_wid(const char *str, t_conversion *conv, va_list ap, int i)
{
	if (str[i] == '0' || str[i] == '-')
	{
		conv->flag = str[i];
		while (str[i] == conv->flag)
			i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		conv->width = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (str[i] == '*')
	{
		conv->width = va_arg(ap, int);
		if (conv->width < 0)
		{
			conv->width *= -1;
			conv->flag = '-';
		}
		i++;
	}
	return (i);
}

void			get_pre(const char *str, t_conversion *conv, va_list ap, int i)
{
	if (str[i] == '.')
	{
		i++;
		conv->precision = 0;
		if (str[i] >= '0' && str[i] <= '9')
		{
			conv->precision = ft_atoi(&str[i]);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		if (str[i] == '*')
		{
			conv->precision = va_arg(ap, int);
			i++;
		}
	}
	conv->type = str[i];
}

int				display_precision(t_conversion conv, char *s)
{
	int		diff;
	int		count_v;

	if (conv.precision < 0)
		return (0);
	diff = conv.precision - ft_strlen(s);
	count_v = (diff < 0) ? 0 : diff;
	if (s[0] == '-' && diff + 1 > 0)
	{
		diff++;
		count_v++;
		count_v += write(1, "-", 1);
	}
	while (diff > 0)
	{
		write(1, "0", 1);
		diff--;
	}
	return (count_v);
}

int		display_width(t_conversion conv, char *s)
{
	char	sp;
	int		len;
	int		diff;
	int		count_v;

	sp = (conv.flag == '0') ? '0' : ' ';
	len = (s[0] == '-') ? ft_strlen(s) - 1 : ft_strlen(s);
	if (conv.precision > len)
		diff = (s[0] == '-') ? conv.width - conv.precision - 1 : conv.width - conv.precision;
	else
		diff = conv.width - ft_strlen(s);
	count_v = (diff < 0) ? 0 : diff;
	sp = (conv.flag == '0') ? '0' : ' ';
	if (conv.flag == '0' && s[0] == '-')
		count_v += write(1, "-", 1);
	while (diff > 0)
	{
		write(1, &sp, 1);
		diff--;
	}
	return (count_v);
}
