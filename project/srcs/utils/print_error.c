
#include "../../incs/cub3D.h"

int getstrlen(char *str){
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

int print_error(char *mes)
{
    write(2, "Error\n", 6);
    write(2, mes, getstrlen(mes));
    return (1);
}