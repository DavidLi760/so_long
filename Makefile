NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Imlx
LFLAGS		= -Lmlx -lmlx -lX11 -lXext -lXrandr -lm
LIBFT		= libft/libft.a
PRINTF		= ft_printf/libftprintf.a
SRC			=	main.c \
				parsing.c \
				parsing2.c \
				utils.c
OBJ			= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME) $(LFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
	rm -rf $(OBJ)

.PHONY: all clean fclean re
