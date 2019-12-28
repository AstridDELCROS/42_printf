/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:31:43 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/27 21:39:51 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_type_c(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	write(1, &c, 1);
}

void	ft_type_s(va_list ap)
{
	char *str;

	str = va_arg(ap, char*);
	write(1, str, ft_strlen(str));
}

void	ft_type_percent(va_list ap)
{
	char percent;

	percent = '%';
	write(1, &percent, 1);
}
