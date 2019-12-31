/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:49:36 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 02:38:25 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	apply_type(t_conversion conv, va_list ap)
{
	if (conv.type == 'c')
		return (ft_type_c(ap, conv));
	if (conv.type == 's')
		return (ft_type_s(ap, conv));
	if (conv.type == 'd')
		return (ft_type_d(ap, conv));
	if (conv.type == 'i')
		return (ft_type_i(ap, conv));
	if (conv.type == 'u')
		return (ft_type_u(ap, conv));
	if (conv.type == '%')
		return (ft_type_percent(conv));
	if (conv.type == 'x')
		return (ft_type_x(ap, conv));
	if (conv.type == 'X')
		return (ft_type_xmaj(ap, conv));
	if (conv.type == 'p')
		return (ft_type_p(ap, conv));
	return (0);
}
