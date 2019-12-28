/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:58:16 by adelcros          #+#    #+#             */
/*   Updated: 2019/12/27 21:54:53 by adelcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFFER_SIZE 9
#include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*
typedef struct T_LIST
{
	char	minus;
	int		width;
	int		precision;
	char	type;
}	t_flags;
*/

typedef struct	s_conversion
{
	char	flag;
	int		width;
	int		precision;
	char	type;
}				t_conversion;

void	ft_type_c(va_list ap);
void	ft_type_s(va_list ap);
void	ft_type_percent(va_list ap);
void	ft_type_d(va_list ap);
void	ft_type_i(va_list ap);
void	ft_type_u(va_list ap);
void	ft_type_x(va_list ap);
void	ft_type_X(va_list ap);
void	ft_type_p(va_list ap);
void	apply_type(t_conversion conv, va_list ap);
t_conversion	get_conversion(const char *str, t_conversion conv, va_list ap);
#endif
