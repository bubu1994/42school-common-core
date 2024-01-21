
NAME = push_swap

SRCS =	operations/push.c operations/rotate.c operations/rrotate.c \
		operations/swap.c check_args.c createpile_andfree.c getmaxmin.c \
		libft.c push_swap.c tri.c algorithm.c operate.c sorting_to_b.c \
		pulling_from_b.c targets_of_a.c

OBJS = ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -f

${NAME}:	${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all