NAME = cub3D
CC = cc
GNL = libs/get_next_line/
SRC = srcs/main.c \
	srcs/parser/meta_init.c \
	srcs/parser/parser.c \
	srcs/utils/print_error.c \
	srcs/utils/safe_malloc.c \
	$(GNL)get_next_line.c \
	$(GNL)get_next_line_utils.c

OBJ = ${SRC:.c=.o}

LIBFT_PATH	= ./libs/libft
LIBFT_NAME	= libft.a
	
FLAGS = -Wall -Wextra #-Werror - на Ubuntu  -Werror кидает ошибку, если переменная нигде не используется

# ifeq ($(shell uname), Darwin) #проверяем имя системы, Darwin - имя системы на школьных компах
# 	MLXPATH = /usr/local/lib
# 	MINILIBX =  
# 	LIBS = -L$(MLXPATH) -lmlx -framework OpenGL -framework AppKit
# else
# 	MLXPATH = ../libs/mlx_linux
# 	MINILIBX = $(MLXPATH)/libmlx_Linux.a 
# 	LIBS = -L$(MLXPATH) -lmlx_Linux -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm #-lz #//usr/lib/x86_64-linux-gnu - папка в которой лежит libm.a - математическая библиотека
# endif

# INCS = -I$(MLXPATH) -Iincs/

all: $(NAME)

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

# $(NAME): ${LIBFT_PATH}/${LIBFT_NAME} $(MINILIBX) $(OBJ)
# 	$(CC) ${LIBFT_PATH}/${LIBFT_NAME} $(OBJ) $(LIBS) -o $(NAME)
$(NAME): ${LIBFT_PATH}/${LIBFT_NAME} $(OBJ)
	$(CC) ${LIBFT_PATH}/${LIBFT_NAME} $(OBJ) $(LIBS) -o $(NAME)

obj/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCS) -c $< -o $@   

# $(MINILIBX):
#	cd $(MLXPATH) && ./configure

clean:
	rm -f $(OBJ)
	cd $(LIBFT_PATH) && make clean

fclean: clean 
	rm -f $(NAME)

fclean_linux: clean 
#	make clean -C $(MLXPATH)
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)
	
re: fclean all 

re_linux: fclean_linux all 

PHONY: all clean fclean re fclean_linux, re_linux