/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_diu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:43:20 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/27 21:45:20 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_type_d(va_list ap)
{
	int d;

	d = va_arg(ap, int);
	write(1, ft_itoa(d), ft_strlen(ft_itoa(d)));
}

void	ft_type_i(va_list ap)
{
	int i;

	i = va_arg(ap, int);
	write(1, ft_itoa(i), ft_strlen(ft_itoa(i)));
}

void	ft_type_u(va_list ap)
{
	unsigned int u;

	u = va_arg(ap, unsigned int);
	write(1, ft_itoa(u), ft_strlen(ft_itoa(u)));
}
