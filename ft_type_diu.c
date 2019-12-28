/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_diu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:43:20 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/28 17:40:57 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

void	ft_type_i(va_list ap, t_conversion conv)
{
	int		i;
	char	*s;

	i = va_arg(ap, int);
	s = ft_itoa(i);
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

void	ft_type_u(va_list ap, t_conversion conv)
{
	unsigned int u;
	char *s;

	u = va_arg(ap, unsigned int);
	s = ft_itoa(u);

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
