/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:55:19 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/29 22:48:29 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_width_c(va_list ap, t_conversion conv)
{
	char c;

	c = va_arg(ap, int);
	if (conv.flag == '-')
	{
		write(1, &c, 1);
		display_width(conv, &c);
	}
	else
	{
		display_width(conv, &c);
		write(1, &c, 1);
	}
}

void	ft_apply_width_s(va_list ap, t_conversion conv)
{
	char *str;
	int diff;
	char sp = ' ';

	str = va_arg(ap, char *);
	diff = (conv.precision > ft_strlen(str)) ? conv.width - ft_strlen(str) : (conv.precision >= 0) ? conv.width - conv.precision : conv.width -ft_strlen(str);
	if (conv.flag == '-')
	{
		if (conv.precision >= 0 && conv.precision < ft_strlen(str))
			write(1, str, conv.precision);
		else
			write(1, str, ft_strlen(str));
		while (diff > 0)
		{
			write(1, &sp, 1);
			diff --;
		}
	}
	else
	{
		while (diff > 0)
		{
			write(1, &sp, 1);
			diff --;
		}
		if (conv.precision >= 0 && conv.precision < ft_strlen(str))
			write(1, str, conv.precision);
		else
			write(1, str, ft_strlen(str));
	}
	//		display_width(conv, str);
}

void	ft_apply_width_di(va_list ap, t_conversion conv)
{
	int		d;
	char	*s;
	int		len;

	d = va_arg(ap, int);
	s = ft_itoa(d);
	len = (conv.flag == '-') ? ft_strlen(s) - 1 : ft_strlen(s);
	if (conv.flag == '-')
	{
		display_precision(conv, s);
		write(1, s, ft_strlen(s));
		display_width(conv, s);
	}
	else
	{
		display_width(conv, s);
		display_precision(conv, s);
		if (s[0] == '-' && (conv.precision > len || conv.flag == '0'))
			write(1, s + 1, ft_strlen(s) - 1);
		else
			write(1, s, ft_strlen(s));
	}
}

void	ft_apply_width_uxX(va_list ap, t_conversion conv)
{
	unsigned int X;
	char *s;

	X = va_arg(ap, unsigned int);
	s = ft_itoa(X);
	if (conv.flag == '-')
	{
		write(1, s, ft_strlen(s));
		display_width(conv, s);
	}
	else
	{
		display_width(conv, s);
		if (conv.flag == '0' && s[0] == '-')
			write(1, s + 1, ft_strlen(s) - 1);
		else
			write(1, s, ft_strlen(s));
	}
}

void	ft_apply_width_p(va_list ap, t_conversion conv)
{
	long long p;
	char *s;

	p = va_arg(ap, long long);
	s = ft_strjoin("0x", ft_itoa_min(p));
	if (conv.flag == '-')
	{
		write(1, s, ft_strlen(s));
		display_width(conv, s);
	}
	else
	{
		display_width(conv, s);
		write(1, s, ft_strlen(s));
	}
}
