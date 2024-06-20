NAME		= so_long
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -Imlx
LFLAGS		= -Lmlx -lmlx -lX11 -lXext -lXrandr -lm
SRC		=	main.c
OBJ		= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
	rm -rf $(OBJ)

.PHONY: all clean fclean re
