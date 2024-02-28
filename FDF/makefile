NAME =		fdf

CC =		gcc

FLAGS =		-Wall -Werror -Wextra

MAC_FW =	-framework OpenGL -framework Appkit

SRC = 		srcs/main_fdf.c srcs/utils.c srcs/draw.c srcs/env_init.c srcs/pull_color.c \
			srcs/ft_super_split.c srcs/ft_weak_ftoa.c srcs/draw_black.c \
			srcs/handle_events.c srcs/events_instructions.c srcs/check_file.c

OBJ = ${SRC:.c=.o}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	make -s -C libft
	make -s -C minilibx
	${CC} ${OBJ} ./libft/libft.a ./minilibx/libmlx.a ${MAC_FW} -o ${NAME}

all:	${NAME}

clean:
	make clean -s -C libft
	make clean -s -C minilibx
	rm -f ${OBJ}

fclean:	clean
	make fclean -s -C libft
	rm -f ${NAME}

re: fclean all