# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelcros <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 14:57:14 by adelcros          #+#    #+#              #
#    Updated: 2019/12/31 15:26:38 by adelcros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
HEADER= printf.h
CC= gcc
CCFLAGS= -Wall -Wextra -Werror
SRC= ft_atoi.c ft_itoa.c ft_strjoin.c ft_strlen.c ft_apply_type.c \
		ft_convert_type.c ft_convert_s.c ft_type_csp100.c \
		ft_type_diu.c ft_handle_conv.c ft_type_px.c ft_printf.c

OBJ= $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) -I$(HEADER) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	/bin/rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
