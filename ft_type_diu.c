/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_diu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:43:20 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 15:06:47 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_d(va_list ap, t_conversion conv)
{
	char	**s;
	int		res;

	s = malloc(sizeof(char *));
	res = ft_convert_di(ap, conv, s);
	free(*s);
	free(s);
	return (res);
}

int		ft_type_i(va_list ap, t_conversion conv)
{
	char	**s;
	int		res;

	s = malloc(sizeof(char *));
	res = ft_convert_di(ap, conv, s);
	free(*s);
	free(s);
	return (res);
}

int		ft_type_u(va_list ap, t_conversion conv)
{
	char	**s;
	int		res;

	s = malloc(sizeof(char *));
	res = ft_convert_ux(ap, conv, s);
	free(*s);
	free(s);
	return (res);
}

