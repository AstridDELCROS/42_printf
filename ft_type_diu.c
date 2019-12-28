/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_diu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:43:20 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/28 21:26:49 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_type_d(va_list ap, t_conversion conv)
{
	ft_apply_minus_di(ap, conv);
	ft_apply_zero(ap, conv);
}

void	ft_type_i(va_list ap, t_conversion conv)
{
	ft_apply_minus_di(ap, conv);
	ft_apply_zero(ap, conv);
}

void	ft_type_u(va_list ap, t_conversion conv)
{
	ft_apply_minus_uxX(ap, conv);
}

