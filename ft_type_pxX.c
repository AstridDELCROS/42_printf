/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_pxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:45:43 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/30 17:44:08 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_type_p(va_list ap, t_conversion conv)
{
	return (ft_apply_width_p(ap, conv));
}

int		ft_type_x(va_list ap, t_conversion conv)
{
	return (ft_apply_width_uxX(ap, conv));
}

int		ft_type_X(va_list ap, t_conversion conv)
{
	return (ft_apply_width_uxX(ap, conv));
}

