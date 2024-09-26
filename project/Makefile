NAME = cub3D
CC = cc
SRC = srcs/main.c
OBJ = ${patsubst srcs/%.c, obj/%.o, $(SRC)} #patsubst - функция подстановки строки

MLXPATH = ../libs/mlx_linux
MINILIBX = $(MLXPATH)/libmlx_Linux.a 
FLAGS = -I$(MLXPATH) -Wall -Wextra #-Werror - на Ubuntu  -Werror кидает ошибку, если переменная нигде не используется
LIBS = -L$(MLXPATH) -lmlx_Linux -lmlx -L/usr/lib -lXext -lX11 #-lm -lz

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $@

$(OBJ): $(SRC)
	$(CC) $(FLAGS) $(SRC) -c -o $@ 

$(MINILIBX):
	cd $(MLXPATH) && ./configure

clean:
	rm -f $(OBJ)

fclean: clean 
	make clean -C $(MLXPATH)
	rm -f $(NAME)
	
re: fclean all 

PHONY: all clean fclean re