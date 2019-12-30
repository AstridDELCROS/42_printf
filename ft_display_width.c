/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:58:10 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 00:23:16 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		display_width(t_conversion conv, char *s)
{
	char	sp;
	int		len;
	int		diff;
	int		count_v;

	sp = (conv.flag == '0') ? '0' : ' ';
	len = (s[0] == '-') ? ft_strlen(s) - 1 : ft_strlen(s);
	if (conv.precision > len)
		diff = (s[0] == '-') ? conv.width - conv.precision - 1 : conv.width - conv.precision;
	else
		diff = conv.width - ft_strlen(s);
	count_v = (diff < 0) ? 0 : diff;
	sp = (conv.flag == '0') ? '0' : ' ';
	if (conv.flag == '0' && s[0] == '-')
		count_v += write(1, "-", 1);
	while (diff > 0)
	{
		write(1, &sp, 1);
		diff--;
	}
	return (count_v);
}



