NAME =		philo

CC =		cc #-fsanitize=thread

FLAGS =		-Wall -Werror -Wextra

SRC = 		main_philo.c utils.c init.c monitor.c checkargs_and_getters.c \

OBJ = ${SRC:.c=.o}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

all:	${NAME}

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re: fclean all