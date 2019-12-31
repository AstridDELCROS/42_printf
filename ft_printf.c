/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:38:57 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 01:26:44 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

t_conversion	get_conversion(const char *str, t_conversion conv, va_list ap)
{
	int i;
	conv.flag = 'v';
	conv.width = 0;
	conv.precision = -1;

	i = 1;
	if (str[i] == '0' || str[i] == '-')
	{
		conv.flag = str[i];
		while (str[i] == conv.flag)
			i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
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
		conv.precision = 0;
		if (str[i] >= '0' && str[i] <= '9')
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

int		display_precision(t_conversion conv, char *s)
{
	char	z = '0';
	int		diff;
	int count_v;


	if (conv.precision < 0)
		return (0);
	diff = conv.precision - ft_strlen(s);
	count_v = (diff < 0) ? 0 : diff;
	if (s[0] == '-' && diff + 1 > 0)
	{
		diff++;
		count_v++;
		count_v += write(1, "-", 1);
	}
	while (diff > 0)
	{
		write(1, &z, 1);
		diff --;
	}
	return (count_v);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	va_start(ap, format);
	t_conversion conv;
	int i;
	int count_v;

	i = 0;
	count_v = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			conv = get_conversion(&format[i++], conv, ap);
			count_v += apply_type(conv, ap) -1;
			while (format[i] != conv.type)
				i++;
		}
		i++;
		count_v++;
	}
	return (count_v);
}

#include <limits.h>
int		main(void)
{
	char c;
	char *str;

	c = 'h';
	str = "hello le test";
	ft_printf("\ntest printf ==  %-*.46c helptest\n", 5, c);
	ft_printf("ok ok test %-*.46c over\n", 3, c);
	ft_printf("on teste maintenant avec str = |%-15.5s|, voila\n", str);
	ft_printf("et avec un nombre d = %d !!\n", 45);
	ft_printf("puis i = %i ?!\n", 95);
	ft_printf("puis percent = %5% ?!\n");
	ft_printf("puis hexa_minus = %010x hophop\n", 'j');
	ft_printf("puis hexa_maj = %015X ?!\n", 'B');
	ft_printf("adresse de l'arg  = %20p okkkkk\n", &str);
	ft_printf("puis u = %u ?!\n", 95);
	ft_printf("\n\n--%*c...\n", 15, 'z');
	ft_printf("\n\n||%0i...\n", -8);
	ft_printf("||%.5i--\n", -22); // res = --   22-994770792-- (check apply_z)
	ft_printf("||%.5i--\n", 22);
	ft_printf("||%.5d--\n", 72);
	ft_printf("||%.5d--\n", -72);
	ft_printf("||%.5x--\n", 'f');
	ft_printf("||%.5x--\n", 'f');
    ft_printf("\nTEST ++++++===%.6x!!\n", 42);
	dprintf(1, "\nTEST ++++++===%.6x!!\n", 42);
	dprintf(1,"--%05.10d--\n", 32);
	dprintf(1,"--%0d--\n", 42);
	ft_printf("--%5d--\n", 52);
	dprintf(1,"--%5s--\n", "AY");
	dprintf(1, "\nouss:  **%08d**\n", -1000);
	dprintf(1, "\nouss2: **%08d**\n", 1000);
	dprintf(1, "||%.5i--\n", 22); // res = --   22-994770792-- (check apply_z)
	dprintf(1, "||%015.*i--\n", -10, -2000002);
	dprintf(1, "***** test ========== %5%  \n");
	dprintf(1, "test ITOA === %s", ft_itoa_maj(0));
	dprintf(1, "test ITOA === %s", ft_itoa(0));
	dprintf(1, "test ITOA === %s", ft_itoa_min(0));
	ft_printf("\nHEY TEST === %.0i !!!\n", 0);
	dprintf(1, "\n HEY TESTBIS %.0i", 0);
	ft_printf("%.*d\n", 4, -421);
	ft_printf("%.*d\n", 10, -488353545);
	dprintf(1, "%.*d\n", 0, INT_MAX);
}

