/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:58:10 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/29 18:15:23 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		display_width(t_conversion conv, char *s)
{
	int i;
	char sp;
	int add_sp;

	sp = (conv.flag == '0') ? '0' : ' ';
	if (conv.flag == '0' && s[0] == '-')
		write(1, "-", 1);
	add_sp = conv.width - ft_strlen(s);
	i = 0;
	while (add_sp > 0)
	{
		write(1, &sp, 1);
		add_sp --;
	}
}

