# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckhondji <ckhondji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 15:44:40 by ckhondji          #+#    #+#              #
#    Updated: 2026/03/30 17:18:53 by ckhondji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCFLAGS = cc -Wall -Werror -Wextra -g
LIBFT = libft.a
MLX = libmlx_Linux.a
GNL = libgnl.a
MLX_FLAGS = -lm -lbsd -lmlx -lXext -lX11

NAME = so_long
SRC = src/so_long.c src/map_manager.c src/hook_handler.c src/flood_fill.c src/window_handler.c src/collision_handler.c src/cleanup_vars.c src/window_handler1.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT) $(GNL)
	$(CCFLAGS) $(OBJS) -Llibft -lft get_next_line/get_next_line.c get_next_line/get_next_line_utils.c -Lmlx_linux -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)

$(MLX):
	${MAKE} -s -C ./mlx_linux/

$(LIBFT):
	${MAKE} -s -C ./libft 

$(GNL):
	@echo "Compiling GNL..."
	${MAKE} -s -C ./get_next_line

%.o: %.c
	$(CCFLAGS) -I/usr/include -Imlx_linux -Ilibft -Iget_next_line -O3 -c $< -o $@

clean:
	${MAKE} clean -C ./libft
	${MAKE} clean -C ./mlx_linux/
	${MAKE} clean -C ./get_next_line/
	rm -rf $(OBJS)

fclean: clean
	${MAKE} fclean -C ./libft
	${MAKE} fclean -C ./get_next_line/
	rm -rf $(NAME)

re: fclean all
