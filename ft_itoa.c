/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:28:51 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 15:21:26 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sizecalc(long long n)
{
	int	res;

	res = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

static int	ft_sizecalc_hexa(long long n)
{
	int	res;

	res = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n = n / 16;
		res++;
	}
	return (res);
}

char		*ft_itoa(long long n)
{
	long long		num;
	char			*res;
	int				size;

	num = (n < 0 ? -n : n);
	size = ft_sizecalc(n);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size--] = '\0';
	while (size >= 0)
	{
		res[size] = num % 10 + 48;
		num = num / 10;
		size--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

char		*ft_itoa_min(long long n)
{
	long long	num;
	char		*res;
	int			size;
	int			tmp;

	size = ft_sizecalc_hexa(n);
	num = n;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size--] = '\0';
	while (size >= 0)
	{
		tmp = num % 16;
		num = num / 16;
		if (tmp < 10)
			res[size] = tmp + 48;
		else
			res[size] = tmp + 87;
		size--;
	}
	return (res);
}

char		*ft_itoa_maj(long long n)
{
	long long	num;
	char		*res;
	int			size;
	int			tmp;

	size = ft_sizecalc_hexa(n);
	num = n;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size--] = '\0';
	while (size >= 0)
	{
		tmp = num % 16;
		num = num / 16;
		if (tmp < 10)
			res[size] = tmp + 48;
		else
			res[size] = tmp + 55;
		size--;
	}
	return (res);
}
