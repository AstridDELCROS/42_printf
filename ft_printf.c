/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:38:57 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 02:33:02 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	t_conversion	conv;
	int				i;
	int				count_v;

	va_start(ap, format);
	i = 0;
	count_v = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			conv = get_conversion(&format[i++], conv, ap);
			count_v += apply_type(conv, ap) - 1;
			while (format[i] != conv.type)
				i++;
		}
		i++;
		count_v++;
	}
	return (count_v);
}
