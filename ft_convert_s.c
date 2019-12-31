/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:50:50 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 15:05:15 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_convert_s(va_list ap, t_conversion conv)
{
	char	*str;
	int		diff;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (!(conv.precision > ft_strlen(str)))
	{
		if (conv.precision >= 0)
			diff = conv.width - conv.precision;
		else
			diff = conv.width - ft_strlen(str);
	}
	else
		diff = conv.width - ft_strlen(str);
	return (ft_display_s(str, conv, 0, diff));
}

int		ft_display_s(char *str, t_conversion conv, int count_v, int diff)
{
	if (conv.flag == '-')
	{
		if (conv.precision >= 0 && conv.precision < ft_strlen(str))
			count_v += write(1, str, conv.precision);
		else
			count_v += write(1, str, ft_strlen(str));
		while (diff > 0)
		{
			count_v += write(1, " ", 1);
			diff--;
		}
	}
	else
	{
		while (diff > 0)
		{
			count_v += write(1, " ", 1);
			diff--;
		}
		if (conv.precision >= 0 && conv.precision < ft_strlen(str))
			count_v += write(1, str, conv.precision);
		else
			count_v += write(1, str, ft_strlen(str));
	}
	return (count_v);
}
