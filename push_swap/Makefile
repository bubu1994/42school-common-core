
NAME = push_swap

BONUS_NAME = checker

SRCS =	operations/push.c operations/rotate.c operations/rrotate.c \
		operations/swap.c check_args.c createpile_andfree.c getmaxmin.c \
		libft.c push_swap.c tri.c algorithm.c operate.c sorting_to_b.c \
		pulling_from_b.c targets_of_a.c

BONUS_SRCS = operations/push.c operations/rotate.c operations/rrotate.c \
		operations/swap.c check_args.c createpile_andfree.c libft.c \
		checker_bonus.c getmaxmin.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c checker_bonus_utils.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -f

${NAME}:	${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

${BONUS_NAME}:	${BONUS_OBJS}
	make -C ft_printf
	${CC} ${FLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} ./ft_printf/libftprintf.a

all:	${NAME}

bonus:	${BONUS_NAME}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME} ${BONUS_NAME}

re:	fclean all