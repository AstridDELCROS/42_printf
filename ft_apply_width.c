/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:55:19 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/30 22:16:07 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_apply_width_c(char *c, t_conversion conv)
{
	if (conv.flag == '-')
		return (write(1, c, 1) + display_width(conv, c));
	else
		return (display_width(conv, c) + write(1, c, 1));
}

int		ft_apply_width_s(va_list ap, t_conversion conv)
{
	char *str;
	int diff;
	char sp = ' ';
	int count_v;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	count_v = 0;
	diff = (conv.precision > ft_strlen(str)) ? conv.width - ft_strlen(str) : (conv.precision >= 0) ? conv.width - conv.precision : conv.width -ft_strlen(str);
	if (conv.flag == '-')
	{
		if (conv.precision >= 0 && conv.precision < ft_strlen(str))
			count_v += write(1, str, conv.precision);
		else
			count_v += write(1, str, ft_strlen(str));
		while (diff > 0)
		{
			count_v += write(1, &sp, 1);
			diff --;
		}
	}
	else
	{
		while (diff > 0)
		{
			count_v += write(1, &sp, 1);
			diff --;
		}
		if (conv.precision >= 0 && conv.precision < ft_strlen(str))
			count_v += write(1, str, conv.precision);
		else
			count_v += write(1, str, ft_strlen(str));
	}
	return (count_v);
}

int		ft_apply_width_di(va_list ap, t_conversion conv)
{
	int		d;
	char	*s;
	int		len;
	int count_v;

	count_v = 0;
	d = va_arg(ap, int);
	s = ft_itoa(d);
	len = (conv.flag == '-') ? ft_strlen(s) - 1 : ft_strlen(s);
	if (!conv.precision && !d)
		return (display_width(conv, ""));
	else if (conv.flag == '-')
		return (display_precision(conv, s) + write(1, s, ft_strlen(s)) + display_width(conv, s));
	else
	{
		count_v = display_width(conv, s) + display_precision(conv, s);
		if (s[0] == '-' && (conv.precision > len || conv.flag == '0'))
			count_v += write(1, s + 1, ft_strlen(s) - 1);
		else
			count_v += write(1, s, ft_strlen(s));
	}
	return (count_v);
}

int		ft_apply_width_uxX(va_list ap, t_conversion conv)
{
	unsigned int X;
	char *s;
	int count_v;
	X = va_arg(ap, unsigned int);
	if (conv.type == 'x')
		s = ft_itoa_min(X);
	else if (conv.type == 'X')
		s = ft_itoa_maj(X);
	else
		s = ft_itoa(X);
	count_v = 0;
	if (!conv.precision && X == '0')
	{
		count_v += (display_width(conv, ""));
	}
	else if (conv.flag == '-')
		count_v = display_precision(conv, s) +  write(1, s, ft_strlen(s)) + display_width(conv, s);
	else
		count_v = display_width(conv, s) + display_precision(conv, s) + write(1, s, ft_strlen(s));
	return (count_v);
}

int		ft_apply_width_p(va_list ap, t_conversion conv)
{
	long long p;
	char *s;
	int count_v;

	p = va_arg(ap, long long);
	s = ft_strjoin("0x", ft_itoa_min(p));
	count_v = 0;
	if (conv.flag == '-')
	{
		count_v = write(1, s, ft_strlen(s));
		count_v += display_width(conv, s);
	}
	else
	{
		count_v = display_width(conv, s);
		count_v += write(1, s, ft_strlen(s));
	}
	return (count_v);
}
