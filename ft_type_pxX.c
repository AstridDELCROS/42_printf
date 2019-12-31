/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_pxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:45:43 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 15:07:10 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_p(va_list ap, t_conversion conv)
{
	return (ft_convert_p(ap, conv));
}

int		ft_type_x(va_list ap, t_conversion conv)
{
	char	**s;
	int		res;

	s = malloc(sizeof(char *));
	res = ft_convert_ux(ap, conv, s);
	free(*s);
	free(s);
	return (res);
}

int		ft_type_xmaj(va_list ap, t_conversion conv)
{
	char	**s;
	int		res;

	s = malloc(sizeof(char *));
	res = ft_convert_ux(ap, conv, s);
	free(*s);
	free(s);
	return (res);
}

