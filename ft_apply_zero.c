/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:59:34 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/28 21:27:01 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_zero(va_list ap, t_conversion conv)
{
	int		d;
	char *s;

	d = va_arg(ap, int);
	s = ft_itoa(d);

	if (conv.flag == '0')
	{
		display_width_z(conv, s);
		write(1, s, ft_strlen(s));
	}
}
