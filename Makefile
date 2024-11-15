# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 16:40:58 by tbarret           #+#    #+#              #
#    Updated: 2024/02/25 12:14:27 by tbarret          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRC = src/function/server.c
SERVER_OBJ = ${SERVER_SRC:.c=.o}

CLIENT_SRC = src/function/client.c
CLIENT_OBJ = ${CLIENT_SRC:.c=.o}


CLIENT_NAME = client
SERVER_NAME = server

SERVER_SRC_BONUS = src/function/server_bonus.c
SERVER_OBJ_BONUS = ${SERVER_SRC_BONUS:.c=.o}

CLIENT_SRC_BONUS = src/function/client_bonus.c
CLIENT_OBJ_BONUS = ${CLIENT_SRC_BONUS:.c=.o}


CLIENT_NAME_BONUS = client_bonus
SERVER_NAME_BONUS = server_bonus

FT_PRINTF = src/header/ft_printf/
LIBFT = src/header/libft/
HEADER  = src/header
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${SERVER_NAME} ${CLIENT_NAME}

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

${SERVER_NAME}: ${SERVER_OBJ}
	@make -C ${FT_PRINTF}
	@make -C ${LIBFT}
	${CC} ${CFLAGS} ${SERVER_OBJ} -I ${HEADER} ${LIBFT}libft.a ${FT_PRINTF}libftprintf.a -o ${SERVER_NAME}

${CLIENT_NAME}: ${CLIENT_OBJ}
	@make -C ${FT_PRINTF}
	@make -C ${LIBFT}
	${CC} ${CFLAGS} ${CLIENT_OBJ} -I ${HEADER} ${LIBFT}libft.a ${FT_PRINTF}libftprintf.a -o ${CLIENT_NAME}

${SERVER_NAME_BONUS}: ${SERVER_OBJ_BONUS}
	@make -C ${FT_PRINTF}
	@make -C ${LIBFT}
	${CC} ${CFLAGS} ${SERVER_OBJ_BONUS} -I ${HEADER} ${LIBFT}libft.a ${FT_PRINTF}libftprintf.a -o ${SERVER_NAME_BONUS}

${CLIENT_NAME_BONUS}: ${CLIENT_OBJ_BONUS}
	@make -C ${FT_PRINTF}
	@make -C ${LIBFT}
	${CC} ${CFLAGS} ${CLIENT_OBJ_BONUS} -I ${HEADER} ${LIBFT}libft.a ${FT_PRINTF}libftprintf.a -o ${CLIENT_NAME_BONUS}

clean:
	@make clean -C ${FT_PRINTF}
	@make clean -C ${LIBFT}
	${RM} ${SERVER_OBJ}
	${RM} ${SERVER_OBJ_BONUS}
	${RM} ${CLIENT_OBJ}
	${RM} ${CLIENT_OBJ_BONUS}

fclean: clean
	@make fclean -C ${FT_PRINTF}
	@make fclean -C ${LIBFT}
	${RM} ${SERVER_NAME}
	${RM} ${CLIENT_NAME}
	${RM} ${SERVER_NAME_BONUS}
	${RM} ${CLIENT_NAME_BONUS}

bonus: ${CLIENT_NAME_BONUS} ${SERVER_NAME_BONUS}

re: fclean all

.PHONY : all clean fclean re
