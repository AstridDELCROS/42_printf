/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:38:57 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/28 21:26:57 by adelcros         ###   ########.fr       */
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
	}
	conv.type = str[i];
	return conv;
}

void		display_width(t_conversion conv, char *s)
{
	int i;
	char sp = ' ';

	int add_sp = conv.width - ft_strlen(s);
	i = 0;
	while (add_sp > 0)
	{
		write(1, &sp, 1);
		add_sp --;
	}
}

void	display_width_z(t_conversion conv, char *s)
{
	int i;
	char z = '0';

	int add_z = conv.width - ft_strlen(s);
	i = 0;
	while (add_z > 0)
	{
		write(1, &z, 1);
		add_z --;
	}
}


int		display_precision(t_conversion conv, char *s)
{
	int i;
	int add_z;
	char z = '0';

	i = 0 ;
	add_z = conv.precision - ft_strlen(s);
	while (conv.precision > 0)
	{
		write(1, &z, add_z);
		conv.precision --;
	}
	return (0);
}

/*
void	apply_flags(const char *str, t_conversion conv, va_list)
{
	display_width();
	display_precision();
}
*/

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
	display_str("puis hexa_minus = %10x hophop\n", 'j');
	display_str("puis hexa_maj = %-15X ?!\n", 'B');
	display_str("adresse de l'arg  = %20p okkkkk\n", &str);
	display_str("puis u = %u ?!\n", 95);
	display_str("\n\n--%*c...\n", 15, 'z');
	display_str("\n\n--%-*d...\n", 6, 8);
	display_str("--%05d--\n", 22); // res = --   22-994770792-- (check apply_z)
	dprintf(1,"--%0.2d--\n", 32);
	dprintf(1,"--%0d--\n", 42);
	display_str("--%5d--\n", 52);
	dprintf(1,"--%-.5d--\n", 62);
	dprintf(1, "\nouss: **%10.8d**\n", -1000);
}
