NAME =		minishell

CC =		cc #-fsanitize=address

FLAGS =		-Wall -Werror -Wextra

OBJ_DIR = obj
BUIL_DIR = ./builtins
UTI_DIR = ./utils
EXP_DIR = ./expand
PARSE_DIR = ./parsing
EXEC_DIR = ./execution
REDIR_DIR = ./redirections
SIG_DIR = ./signals

# je crois qu on peut faire un dossier source et tout mettre dedans. ca lit automatiquement
SRCS = 		${shell find ${BUIL_DIR} -type f -name '*.c'}\
			${shell find ${UTI_DIR} -type f -name '*.c'}\
			${shell find ${EXP_DIR} -type f -name '*.c'}\
			${shell find ${PARSE_DIR} -type f -name '*.c'}\
			${shell find ${EXEC_DIR} -type f -name '*.c'}\
			${shell find ${SIG_DIR} -type f -name '*.c'}\
			${shell find ${REDIR_DIR} -type f -name '*.c'}\
			main.c \

RM = rm -f

OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(dir $@)
		${CC} ${FLAGS} -I. -c $< -o $@ 

${NAME}: ${OBJ}
	make -s -C libft
	${CC} ${FLAGS} ${OBJ} ./libft/libft.a -L/Users/${USER}/.brew/opt/readline/lib -I/Users/${USER}/.brew/opt/readline/include -lreadline -o ${NAME}

all:	${NAME}

clean:
			rm -rf $(OBJ_DIR)
			make clean -s -C libft
			${RM} ${OBJ}

fclean:		clean
			make fclean -s -C libft
			${RM} ${NAME}

re: fclean all

.PHONY:		all re clean fclean