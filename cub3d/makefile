NAME 		= cub3D
NAME_BONUS	= cub3D_bonus

CC 			= gcc

FLAGS 		= -Wall -Werror -Wextra

SRC_DIR 	= src

OBJ_DIR 	= obj

SRC_BASE 	= 	main.c pixeling.c handle_keys.c \
				utils.c utils_cleaning.c utils_printing.c \
				minimap.c movement.c \
				raycaster.c raycaster_data.c \
				walldrawer.c init.c textures.c \
				parse_colour.c parse_data.c \
				parse_main.c parse_map.c

SRC 		= $(SRC_BASE) parsing/no_bonus.c
SRC_BONUS 	= $(SRC_BASE) parsing/with_bonus.c

SRC			:= $(addprefix $(SRC_DIR)/, $(SRC))
SRC_BONUS	:= $(addprefix $(SRC_DIR)/, $(SRC_BONUS))

OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS	= $(SRC_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	MLX_DIR = mlx-linux
	MLX_LIB = -lXext -lX11 -lm -lz
else ifeq ($(UNAME_S), Darwin) # macOS
	MLX_DIR = mlx_macos
	MLX_LIB = -framework OpenGL -framework AppKit
endif


${OBJ_DIR}/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	${CC} ${FLAGS} -I/usr/include -I${MLX_DIR} -O3 -c $< -o $@

${NAME}: ${OBJ}
	make -s -C libft
	make -s -C ${MLX_DIR}
	${CC} ${OBJ} ./libft/libft.a ./${MLX_DIR}/libmlx.a ${MLX_LIB} -o ${NAME}

${NAME_BONUS}: ${OBJ_BONUS}
	make -s -C libft
	make -s -C ${MLX_DIR}
	${CC} ${OBJ_BONUS} ./libft/libft.a ./${MLX_DIR}/libmlx.a ${MLX_LIB} -o ${NAME_BONUS}

all: ${NAME}

bonus: ${NAME_BONUS}

clean:
	make clean -s -C libft
	make clean -s -C ${MLX_DIR}
	rm -rf ${OBJ_DIR}

fclean: clean
	make fclean -s -C libft
	rm -f ${NAME} ${NAME_BONUS}

re: fclean all
