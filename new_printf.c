/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:38:57 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/28 01:44:07 by adelcros         ###   ########.fr       */
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
		while (str[i] >= '1' && str[i] <= '9')
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
			while (str[i] >= '1' && str[i] <= '9')
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

void		display_width(t_conversion conv, va_list ap)
{
	int i;
	char sp = ' ';

	i = 0;
	while (conv.width > 0)
	{
		write(1, &sp, 1);
		conv.width --;
	}
// pour les num =
// num = va_arg(ap, int);
// lennum = ft_strlen(num);
// if (conv.width > lennum)
// {
//		add_z = conv.width - lennum;
//		while (add_z > 0)
//			write(1, '0', add_z);
// }
}

int		ft_strleni(int n)
{
	int i;

	i = 0;
	while (ft_itoa(n)[i])
		i++;
	return (i);
}

int		display_precision(t_conversion conv, va_list ap)
{
	int i;
	int lennum;
	int num;
	int add_z;
	char z = 'z';

	num = va_arg(ap, int);
	i = 0 ;
	if (!(ft_isdigit(num)))
		return (1);
	lennum = ft_strleni(num);
	add_z = conv.precision - lennum;
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
//			apply_flags(&format[i], conv, ap);
			display_width(conv, ap);
//			display_precision(conv, ap);
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
	display_str("\ntest printf ==  %-*.46c helptest\n", 5, c);  //plante si je mets un \n
	display_str("ok ok test %-*.46c over\n", 3, c);  //plante si je mets un \n
	display_str("on teste maintenant avec str = %s, voila\n", str);
	display_str("et avec un nombre d = %d !!\n", 45);
	display_str("puis i = %i ?!\n", 95);
	display_str("puis percent = %% ?!\n");
	display_str("puis hexa_minus = %x hophop\n", 'j');
	display_str("puis hexa_maj = %X ?!\n", 'B');
	display_str("adresse de l'arg  = %p okkkkk\n", &str);
	display_str("puis u = %u ?!\n", 95);
	display_str("\n\n--%8c--\n",'z');
	dprintf(1,"--%.5d--\n", 22);
	dprintf(1,"--%5.3d--\n", 32);
	dprintf(1,"--%0d--\n", 42);
	display_str("--%5d--\n", 52);
	dprintf(1,"--%-.5d--\n", 62);
	dprintf(1, "\nouss: **%10.8d**\n", -1000);
}
