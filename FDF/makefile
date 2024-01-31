NAME = fdf

MLX = minilibx/
MLX_A = minilibx/libmlx.a

LIBFT = libft/
LIBFT_A = libft/libft.a

INCLUDES = includes

CC = gcc

FLAGS = -Wall -Wextra -Werror

MAC_FWs = -framework OpenGL -framework AppKit

SRC = fdf.c utils.c create_lst_and_free.c ft_super_split.c useless.c\
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = ${SRC:.c=.o}

all:	${NAME}

${NAME}:	${OBJ} ${MLX_A} ${LIBFT_A}
	${CC} ${FLAGS} -I./includes/fdf.h ${OBJ}  -L${MLX} -lmlx -L${LIBFT} -lft ${MAC_FWs} -o ${NAME}
	
${MLX_A}:
	make -s -C ${MLX}

${LIBFT_A}:
	make -s -C ${LIBFT}

clean:
	make clean -C ${LIBFT}
	make clean -C ${MLX}
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re: fclean all
