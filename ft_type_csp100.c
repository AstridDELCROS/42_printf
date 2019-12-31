/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:31:43 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 15:04:48 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_c(va_list ap, t_conversion conv)
{
	char c;

	c = va_arg(ap, int);
	return (ft_convert_c(c, conv));
}

int		ft_type_s(va_list ap, t_conversion conv)
{
	return (ft_convert_s(ap, conv));
}

int		ft_type_percent(t_conversion conv)
{
	return (ft_convert_c('%', conv));
}
