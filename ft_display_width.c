/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:58:10 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/29 21:52:54 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		display_width(t_conversion conv, char *s)
{
	char	sp;
	int		len;
	int		diff;

	sp = (conv.flag == '0') ? '0' : ' ';
	len = (s[0] == '-') ? ft_strlen(s) - 1 : ft_strlen(s);
	if (conv.precision > len)
		diff = (s[0] == '-') ? conv.width - conv.precision - 1 : conv.width - conv.precision;
	else
		diff = conv.width - ft_strlen(s);
	sp = (conv.flag == '0') ? '0' : ' ';
	if (conv.flag == '0' && s[0] == '-')
		write(1, "-", 1);
	while (diff > 0)
	{
		write(1, &sp, 1);
		diff--;
	}
}

