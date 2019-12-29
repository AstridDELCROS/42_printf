/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_pxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:45:43 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/29 18:09:37 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_type_p(va_list ap, t_conversion conv)
{
	ft_apply_width_p(ap, conv);
}

void	ft_type_x(va_list ap, t_conversion conv)
{
	ft_apply_width_uxX(ap, conv);
}

void	ft_type_X(va_list ap, t_conversion conv)
{
	ft_apply_width_uxX(ap, conv);
}

