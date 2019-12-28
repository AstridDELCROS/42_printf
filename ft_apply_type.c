/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:49:36 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/27 21:54:23 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	apply_type(t_conversion conv, va_list ap)
{
	if (conv.type == 'c')
		ft_type_c(ap);
	if (conv.type == 's')
		ft_type_s(ap);
	if (conv.type == 'd')
		ft_type_d(ap);
	if (conv.type == 'i')
		ft_type_i(ap);
	if (conv.type == 'u')
		ft_type_u(ap);
	if (conv.type == '%')
		ft_type_percent(ap);
	if (conv.type == 'x')
		ft_type_x(ap);
	if (conv.type == 'X')
		ft_type_X(ap);
	if (conv.type == 'p')
		ft_type_p(ap);
}
