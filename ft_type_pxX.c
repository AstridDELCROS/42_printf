/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_pxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:45:43 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/28 18:40:58 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
void	ft_type_d(va_list ap, t_conversion conv)
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
*/


void	ft_type_p(va_list ap, t_conversion conv)
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

void	ft_type_x(va_list ap, t_conversion conv)
{
	unsigned int x;
	char *s;

	x = va_arg(ap, unsigned int);
	s = ft_itoa(x);
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

void	ft_type_X(va_list ap, t_conversion conv)
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
