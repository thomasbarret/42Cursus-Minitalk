# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 16:40:58 by tbarret           #+#    #+#              #
#    Updated: 2023/12/06 16:41:00 by tbarret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = \
	ft_printchar.c \
	ft_printf.c \
	ft_printhex.c \
	ft_printnbr.c \
	ft_printptr.c \
	ft_printstr.c \
	ft_printunbr.c \

OBJ = ${SRC:.c=.o}
CC = cc
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libftprintf.a

all: ${NAME}

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ} ft_printf.h
	${AR} $@ $^

clean:
	${RM} ${OBJ} ${BOBJ}

fclean: clean
	${RM} ${NAME}

bonus: all

re: fclean all

.PHONY : all clean fclean re
