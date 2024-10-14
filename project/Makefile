NAME = cub3D
CC = cc
GNL = libs/get_next_line/
DRAW = buttons.c hooks.c mlx.c render.c t_pos.c
SRC = srcs/main.c \
    srcs/debug/debug.c \
    srcs/free_res/free_arr.c \
    srcs/free_res/free_grid.c \
    srcs/free_res/free_line.c \
    srcs/player/init_player.c \
    srcs/player/set_fov.c \
    srcs/player/set_direction.c \
    srcs/parser/meta_init.c \
    srcs/parser/parser.c \
    srcs/parser/parse_dir.c \
    srcs/parser/parse_map.c \
    srcs/parser/check_map.c \
    srcs/raycast/delta_len.c \
    srcs/raycast/find_wall.c \
    srcs/raycast/get_grid.c \
    srcs/raycast/get_line_inds.c \
    srcs/raycast/get_vectors_cos_angle.c \
    srcs/raycast/ray_hit_len.c \
    srcs/raycast/raycast.c \
    srcs/utils/print_error.c \
    srcs/utils/ft_isspace.c \
    srcs/utils/safe_malloc.c \
    srcs/utils/check_color.c \
    srcs/utils/ft_addline.c \
    $(GNL)get_next_line.c \
    $(GNL)get_next_line_utils.c \
    $(addprefix srcs/draw/, $(DRAW))

OBJ = ${SRC:.c=.o}

LIBFT_PATH	= libs/libft
LIBFT_NAME	= libft.a
LIBS = -L$(LIBFT_PATH) -lft

FLAGS = -Wall -Wextra -g -fsanitize=address #-Werror - на Ubuntu  -Werror кидает ошибку, если переменная нигде не используется

ifeq ($(shell uname), Darwin) #проверяем имя системы, Darwin - имя системы на школьных компах
	MLXPATH = libs/mlx_mac
	MINILIBX = $(MLXPATH)/libmlx.a 
	LIBS += -L$(MLXPATH) -lmlx -framework OpenGL -framework AppKit
else
	MLXPATH = libs/mlx_linux
	MINILIBX = $(MLXPATH)/libmlx_Linux.a 
	LIBS += -L$(MLXPATH) -lmlx_Linux -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm #-lz #//usr/lib/x86_64-linux-gnu - папка в которой лежит libm.a - математическая библиотека
endif

INCS = -I$(MLXPATH) -I./incs/

all: $(NAME)

$(NAME): ${LIBFT_PATH}/${LIBFT_NAME} $(MINILIBX) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)
# $(NAME): ${LIBFT_PATH}/${LIBFT_NAME} $(OBJ)
# 	$(CC) ${LIBFT_PATH}/${LIBFT_NAME} $(OBJ) $(LIBS) -o $(NAME)

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

$(MINILIBX):
	make -C $(MLXPATH)

%.o: %.c
	$(CC) $(FLAGS) $(INCS) -c $< -o $@   

clean:
	rm -f $(OBJ)
	cd $(LIBFT_PATH) && make clean

fclean: clean 
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)
	make clean -C $(MLXPATH)

re: fclean all 

# fclean_linux: clean fclean
# re_linux: fclean_linux all 

PHONY: all clean fclean re fclean_linux, re_linux