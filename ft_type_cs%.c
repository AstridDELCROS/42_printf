/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:31:43 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/28 20:53:59 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_type_c(va_list ap, t_conversion conv)
{
	ft_apply_minus_c(ap, conv);
}

void	ft_type_s(va_list ap, t_conversion conv)
{
	ft_apply_minus_s(ap, conv);
}

void	ft_type_percent(va_list ap)
{
	char percent;

	percent = '%';
	write(1, &percent, 1);
}
