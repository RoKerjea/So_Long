SRCS		= srcs/so_long.c srcs/map_parser.c lib/ft_split.c lib/ft_strjoin.c lib/ft_strlen.c lib/ft_strchr.c
SRCS		:= $(SRCS) srcs/getmapinfo.c srcs/keyparser.c

HEADER		= include/so_long.h
RM			= rm -rf
NAME		= so_long
CC			= gcc
OBJECTS		= ${SRCS:.c=.o} ${LIB:.c=.o}
CFLAGS		= -Wall -Werror -Wextra
MLX			= -Lmlx -lmlx -framework OpenGL -framework AppKit

${NAME}:	${HEAD} ${OBJECTS}
	${CC} ${CFLAGS} ${MLX} -o ${NAME} ${OBJECTS}

all:		${NAME}

%.o: %.c %.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:		
	${RM} ${OBJECTS}

fclean:
	${RM} ${OBJECTS}
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re