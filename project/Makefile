NAME = cub3D
CC = cc
SRC = srcs/main.c \
	  srcs/print_error.c \
	  srcs/map_converter.c \
	  srcs/free_res.c \
	  srcs/debug.c

OBJ = ${patsubst srcs/%.c, obj/%.o, $(SRC)} #patsubst - функция подстановки строки
	
FLAGS = -Wall -Wextra -g #-Werror - на Ubuntu  -Werror кидает ошибку, если переменная нигде не используется

ifeq ($(shell uname), Darwin) #проверяем имя системы, Darwin - имя системы на школьных компах
	MLXPATH = /usr/local/lib
	MINILIBX =  
	LIBS = -L$(MLXPATH) -lmlx -framework OpenGL -framework AppKit
else
	MLXPATH = ../libs/mlx_linux
	MINILIBX = $(MLXPATH)/libmlx_Linux.a 
	LIBS = -L$(MLXPATH) -lmlx_Linux -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm #-lz #//usr/lib/x86_64-linux-gnu - папка в которой лежит libm.a - математическая библиотека
endif

INCS = -I$(MLXPATH) -Iincs/

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

obj/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCS) -c $< -o $@   

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

re_linux: fclean_linux all 

PHONY: all clean fclean re fclean_linux, re_linux