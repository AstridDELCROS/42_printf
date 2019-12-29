/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:38:57 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/29 22:01:41 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

t_conversion	get_conversion(const char *str, t_conversion conv, va_list ap)
{
	int i;

	i = 1;
	if (str[i] == '0' || str[i] == '-')
	{
		conv.flag = str[i];
		while (str[i] == conv.flag)
			i++;
	}
	if (str[i] >= '1' && str[i] <= '9')
	{
		conv.width = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (str[i] == '*')
	{
		conv.width = va_arg(ap, int);
		if (conv.width < 0)
		{
			conv.width *= -1;
			conv.flag = '-';
		}
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		if (str[i] >= '1' && str[i] <= '9')
		{
			conv.precision = ft_atoi(&str[i]);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		if (str[i] == '*')
		{
			conv.precision = va_arg(ap, int);
			i++;
		}
		if (conv.precision >= 0 && conv.flag == '0')
			conv.flag = 'v';
	}
	conv.type = str[i];
	return conv;
}

void		display_precision(t_conversion conv, char *s)
{
	char	z = '0';
	int		diff;

	if (conv.precision < 0)
		return ;
	diff = conv.precision - ft_strlen(s);
	if (s[0] == '-')
	{
		diff++;
		write(1, "-", 1);
	}
	while (diff > 0)
	{
		write(1, &z, 1);
		diff --;
	}
}

char	display_str(const char *format, ...)
{
	va_list	ap;
	va_start(ap, format);
	t_conversion conv;
	int i;

	i = 0;
	conv.flag = 'v';
	conv.width = 0;
	conv.precision = -1;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			conv = get_conversion(&format[i], conv, ap);
			apply_type(conv, ap);
			while (format[i] != conv.type)
				i++;
		}
		i++;
	}
	return (0);
}

int		main(void)
{
	char c;
	char *str;

	c = 'h';
	str = "hello le test";
	display_str("\ntest printf ==  %-*.46c helptest\n", 5, c);
	display_str("ok ok test %-*.46c over\n", 3, c);
	display_str("on teste maintenant avec str = %30s, voila\n", str);
	display_str("et avec un nombre d = %d !!\n", 45);
	display_str("puis i = %i ?!\n", 95);
	display_str("puis percent = %% ?!\n");
	display_str("puis hexa_minus = %010x hophop\n", 'j');
	display_str("puis hexa_maj = %015X ?!\n", 'B');
	display_str("adresse de l'arg  = %20p okkkkk\n", &str);
	display_str("puis u = %u ?!\n", 95);
	display_str("\n\n--%*c...\n", 15, 'z');
	display_str("\n\n||%0i...\n", -8);
	display_str("||%.5i--\n", 22); // res = --   22-994770792-- (check apply_z)
	display_str("||%.5i--\n", -22); // res = --   22-994770792-- (check apply_z)
	dprintf(1,"--%05.10d--\n", 32);
	dprintf(1,"--%0d--\n", 42);
	display_str("--%5d--\n", 52);
	dprintf(1,"--%5s--\n", "AY");
	dprintf(1, "\nouss:  **%08d**\n", -1000);
	dprintf(1, "\nouss2: **%08d**\n", 1000);
	dprintf(1, "||%.5i--\n", 22); // res = --   22-994770792-- (check apply_z)
	dprintf(1, "||%015.*i--\n", -10, -2000002); 
}
