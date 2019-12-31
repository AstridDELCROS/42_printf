/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 21:30:14 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/31 14:57:05 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*both_str;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	both_str = malloc(sizeof(both_str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(both_str))
		return (NULL);
	while (s1[i] != '\0')
	{
		both_str[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)] != '\0')
	{
		both_str[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	both_str[i] = '\0';
	return (both_str);
}
