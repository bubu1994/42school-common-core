NAME	= libftprintf.a

SRCS	= ft_printf.c ft_printcspdiuxX.c

HEADERS = ft_printf.h

OBJS	= ${SRCS:.c=.o}

FLAGS	= -Wall -Werror -Wextra

CC		= gcc

RM		= rm -f

LIB		= ar -rcs

all:	${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${HEADERS}

${NAME}:	${OBJS}
	${LIB} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:		fclean ${NAME}