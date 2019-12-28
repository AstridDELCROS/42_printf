/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:55:19 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/28 20:54:02 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_minus_c(va_list ap, t_conversion conv)
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

void	ft_apply_minus_s(va_list ap, t_conversion conv)
{
	char *str;

	str = va_arg(ap, char*);
	if (conv.flag == '-')
	{
		write(1, str, ft_strlen(str));
		display_width(conv, str);
	}
	else
	{
		display_width(conv, str);
		write(1, str, ft_strlen(str));
	}
}

void	ft_apply_minus_di(va_list ap, t_conversion conv)
{
	int		d;
	char	*s;

	d = va_arg(ap, int);
	s = ft_itoa(d);
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

void	ft_apply_minus_uxX(va_list ap, t_conversion conv)
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
		write(1, s, ft_strlen(s));
	}
}

void	ft_apply_minus_p(va_list ap, t_conversion conv)
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
