NAME = libgnl.a
SRC = get_next_line.c get_next_line_utils.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
