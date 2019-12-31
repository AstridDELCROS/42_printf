/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:38:57 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 15:10:07 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list			ap;
	t_conversion	conv;
	int				i;
	int				count_v;

	va_start(ap, format);
	i = 0;
	count_v = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			conv = get_conversion(&format[i++], conv, ap);
			count_v += ft_apply_type(conv, ap) - 1;
			while (format[i] != conv.type)
				i++;
		}
		i++;
		count_v++;
	}
	return (count_v);
}
