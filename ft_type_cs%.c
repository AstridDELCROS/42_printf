/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:31:43 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/29 18:08:34 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_type_c(va_list ap, t_conversion conv)
{
	ft_apply_width_c(ap, conv);
}

void	ft_type_s(va_list ap, t_conversion conv)
{
	ft_apply_width_s(ap, conv);
}

void	ft_type_percent(va_list ap)
{
	char percent;

	percent = '%';
	write(1, &percent, 1);
}
