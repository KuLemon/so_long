# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/03 19:42:52 by ckhondji          #+#    #+#              #
#    Updated: 2025/12/04 18:36:42 by ckhondji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c ft_putptr.c ft_putunbr.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./

OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: ${NAME}

${NAME} : ${OBJ}
	ar rcs ${NAME} ${OBJ}

clean:
	rm -f ${OBJ} ${DEP}

fclean: clean
	rm -f ${NAME}

re: fclean all

-include ${DEP}

.PHONY: all clean fclean re
