NAME = cub3D
CC = cc
SRC = srcs/main.c
OBJ = ${patsubst srcs/%.c, obj/%.o, $(SRC)} #patsubst - функция подстановки строки
	
FLAGS = -Wall -Wextra #-Werror - на Ubuntu  -Werror кидает ошибку, если переменная нигде не используется

ifeq ($(shell uname), Darwin)
	TEST = Darwin
else
	TEST = Linux
endif
MLXPATH_LINUX = ../libs/mlx_linux
MINILIBX = $(MLXPATH_LINUX)/libmlx_Linux.a 
INCS_LINUX = -I$(MLXPATH_LINUX)
LIBS_LINUX = -L$(MLXPATH_LINUX) -lmlx_Linux -L/usr/lib -lXext -lX11 #-lm -lz

MLXPATH_MAC = /usr/local/lib
LIBS_MAC = -L$(MLXPATH_MAC) -lmlx -framework OpenGL -framework AppKit
INCS_MAC = -I$(MLXPATH_MAC)

all: mac

mac: $(NAME) $(OBJ)
	$(CC) $(OBJ) $(INCS_MAC) $(LIBS_MAC) -o $(NAME)

$(NAME):
	echo $(TEST)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) $(SRC) -c -o $@ 

linux: $(NAME) $(MINILIBX) $(OBJ)
	$(CC) $(OBJ) $(INCS_LINUX) $(LIBS_LINUX) -o $(NAME)

$(MINILIBX):
	cd $(MLXPATH) && ./configure

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

fclean_linux: clean 
	make clean -C $(MLXPATH)
	rm -f $(NAME)
	
re: fclean all 

re_linux: fclean all 

PHONY: all clean fclean re linux fclean_linux, re_linux