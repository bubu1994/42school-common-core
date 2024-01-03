FLAGS	= -Wall -Werror -Wextra
CC		= gcc

PRINTF	= ft_printf
LIB		= ./${PRINTF}/libftprintf.a


all: server client

server: server.o
	make -C ${PRINTF}
	${CC} ${FLAGS} -o server server.o ${LIB}

client: client.o
	make -C ${PRINTF}
	${CC} ${FLAGS} -o client client.o ${LIB}

server.o: server.c
	${CC} -c server.c

client.o: client.c
	${CC} -c client.c

bonus: server_bonus client_bonus

server_bonus: server_bonus.o
	make -C ${PRINTF}
	${CC} -o server_bonus server_bonus.o ${LIB}

client_bonus: client_bonus.o
	make -C ${PRINTF}
	${CC} -o client_bonus client_bonus.o ${LIB}

server_bonus.o: server_bonus.c
	${CC} ${FLAGS} -c server_bonus.c

client_bonus.o: client_bonus.c
	${CC} ${FLAGS} -c client_bonus.c

clean:
	make clean -C ${PRINTF}
	rm -f server.o client.o server_bonus.o client_bonus.o

fclean: clean
	make fclean -C ${PRINTF}
	rm -f server client server_bonus client_bonus

re: fclean all