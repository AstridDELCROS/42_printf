/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_pxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:45:43 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/27 21:46:49 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_type_p(va_list ap)
{
	long long p;
	char *s;
	p = va_arg(ap, long long);
	s = ft_strjoin("0x", ft_itoa_min(p));
	write(1, s, ft_strlen(s));
}

void	ft_type_x(va_list ap)
{
	unsigned int x;

	x = va_arg(ap, unsigned int);
	write(1, ft_itoa_min(x), ft_strlen(ft_itoa_min(x)));
}

void	ft_type_X(va_list ap)
{
	unsigned int X;

	X = va_arg(ap, unsigned int);
	write(1, ft_itoa_maj(X), ft_strlen(ft_itoa_maj(X)));
}
