
NAME	=	so_long

LIB		=	-L ./Libft -L ./minilibx-linux -lmlx -lXext -lX11
HEADER		= include/so_long.h
SRC		=	test.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CF		=	-Wall -Wextra -Werror

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			make -C minilibx-linux
			$(CC) -o $(NAME) $(SRC) ${HEADER} $(LIB)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)
			make -C minilibx-linux clean

re		:	fclean all

.PHONY	:	all clean fclean re