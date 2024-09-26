CC = cc
SRC = srcs/main.c
OBJ = ${patsubst srcs/%.c, obj/%.o, $(SRC)} 
NAME = cub3D
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

$(OBJ):
	$(CC) $(FLAGS) $(SRC) -c  -o $@ 