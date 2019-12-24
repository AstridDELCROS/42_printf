#include "printf.h"
#include <stdio.h>

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
//	dprintf(1, "\n%s !", "c'est un type s");
}

t_conversion	get_conversion(const char *str, t_conversion conv, va_list ap) // ie str = "%*.3d"
{
	int i;

	i = 1;
// On cherche le flag '0' ou '-'
	if (str[i] == '0' || str[i] == '-')
	{
		conv.flag = str[i];
		while (str[i] == conv.flag)
			i++;
	}
// On cherche la taille de champ minimale
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
// On regarde si il y a une précision
	if (str[i] == '.')
	{
		i++;
	// On cherche la valeur de la précision
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
// Type de la conversion
	conv.type = str[i];
	return conv;
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
// Tant que on est pas arrivé a la fin de la chaine de caractère
	while (format[i])
	{
	// Si on ne voit pas de '%'
		if (format[i] != '%')
		//on écrit le caractère
			write(1, &format[i], 1);
		else
		{
			conv = get_conversion(&format[i], conv, ap);
			if (conv.type == 'c')
				ft_type_c(ap);
			if (conv.type == 's')
				ft_type_s(ap);
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
	display_str("ok ok test %-*.46c over\n", 5, c);  //plante si je mets un \n
	display_str("on teste maintenant avec str = %s, voila\n", str);

}
