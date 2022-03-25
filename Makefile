SRCS		= srcs/so_long.c srcs/map_parser.c lib/ft_split.c lib/ft_strjoin.c lib/ft_strlen.c lib/ft_strchr.c
SRCS		:= $(SRCS) srcs/getmapinfo.c srcs/keyparser.c lib/ft_strendcmp.c srcs/printmapshell.c lib/ft_putnbr.c srcs/wincloser.c
SRCS		:= $(SRCS) lib/ft_strdup.c
HEADER		= include/so_long.h
RM			= rm -rf
NAME		= so_long
CC			= gcc
OBJECTS		= ${SRCS:.c=.o}
CFLAGS		= -Wall -Werror -Wextra 
#MLX			= -Lmlx -lmlx -framework OpenGL -framework AppKit

#${NAME}:	${HEAD} ${OBJECTS}
#	${CC} ${CFLAGS} ${MLX} -o ${NAME} ${OBJECTS} -fsanitize=address

LIB		=	-L ./Libft -L ./minilibx-linux -lmlx -lXext -lX11

$(NAME)	:	${OBJECTS}
#			make -C minilibx-linux
			$(CC) ${CFLAGS} -o $(NAME) ${OBJECTS} ${HEADER} $(LIB)

#${NAME}: ${HEAD} ${OBJECTS}
#	$(CC) ${CFLAGS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME} ${OBJECTS}

all:		${NAME}

#%.o: %.c %.h
#	$(CC) $(CFLAGS) -Imlx -c $< -o $@

#%.o: %.c %.h
#	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	${RM} ${OBJECTS}

fclean:
	${RM} ${OBJECTS}
	${RM} ${NAME}
#	make -C minilibx-linux clean

re:			fclean all

.PHONY:		all clean fclean re