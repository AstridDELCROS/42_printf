/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:55:19 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 15:03:39 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_convert_c(char c, t_conversion conv)
{
	int		count_v;
	char	sp;

	count_v = 0;
	conv.precision = -1;
	sp = (conv.flag == '0') ? '0' : ' ';
	if (conv.flag == '-')
	{
		count_v += write(1, &c, 1);
		while (--conv.width > 0)
			count_v += write(1, &sp, 1);
	}
	else
	{
		while (--conv.width > 0)
			count_v += write(1, &sp, 1);
		count_v += write(1, &c, 1);
	}
	return (count_v);
}

int		ft_convert_di(va_list ap, t_conversion conv, char **s)
{
	int		d;
	int		len;

	if (conv.precision >= 0 && conv.flag == '0')
		conv.flag = 'v';
	d = va_arg(ap, int);
	*s = ft_itoa(d);
	len = (s[0][0] == '-') ? ft_strlen(*s) - 1 : ft_strlen(*s);
	if (!conv.precision && !d)
		return (display_width(conv, ""));
	else if (conv.flag == '-')
		if (s[0][0] == '-' && conv.precision > len)
			return (display_precision(conv, *s) +
			write(1, *s + 1, ft_strlen(*s) - 1) + display_width(conv, *s));
		else
			return (display_precision(conv, *s) +
			write(1, *s, ft_strlen(*s)) + display_width(conv, *s));
	else if (s[0][0] == '-' && (conv.precision > len || conv.flag == '0'))
		return (display_width(conv, *s) + display_precision(conv, *s) +
		write(1, *s + 1, ft_strlen(*s) - 1));
	else
		return (display_width(conv, *s) + display_precision(conv, *s) +
		write(1, *s, ft_strlen(*s)));
}

int		ft_convert_ux(va_list ap, t_conversion conv, char **s)
{
	unsigned int	u;
	int				count_v;

	if (conv.precision >= 0 && conv.flag == '0')
		conv.flag = 'v';
	u = va_arg(ap, unsigned int);
	if (conv.type == 'x')
		*s = ft_itoa_min(u);
	else if (conv.type == 'X')
		*s = ft_itoa_maj(u);
	else
		*s = ft_itoa(u);
	count_v = 0;
	if (!conv.precision && u == 0)
	{
		count_v += (display_width(conv, ""));
	}
	else if (conv.flag == '-')
		count_v = display_precision(conv, *s) +
		write(1, *s, ft_strlen(*s)) + display_width(conv, *s);
	else
		count_v = display_width(conv, *s) + display_precision(conv, *s) +
		write(1, *s, ft_strlen(*s));
	return (count_v);
}

int		ft_convert_p(va_list ap, t_conversion conv)
{
	long long	p;
	char		*s;
	char		*t;
	int			count_v;

	p = va_arg(ap, long long);
	t = ft_itoa_min(p);
	s = ft_strjoin("0x", t);
	count_v = 0;
	if (conv.flag == '-')
	{
		count_v = write(1, s, ft_strlen(s));
		count_v += display_width(conv, s);
	}
	else
	{
		count_v = display_width(conv, s);
		count_v += write(1, s, ft_strlen(s));
	}
	free(t);
	free(s);
	return (count_v);
}
