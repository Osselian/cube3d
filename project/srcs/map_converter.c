#include "../incs/cub3D.h"

int arr_len(void **arr){
    int i;

    while (arr[i])
        i++;
    return (i);
}

int str_max_len(void **arr)
{
    int max_len;
    int i;
    int cur_len;
    
    i = 0;
    max_len = 0;
    while (arr[i])
    {
        cur_len = getstrlen(arr[i]);  
        if (cur_len > max_len)
            max_len = cur_len;
        i++;
    }
    return (max_len);
}

int map_converter(char **map, t_line **vert, t_line **hor)
{
    int vert_num;
    int hor_num;
    int i;

    hor_num = arr_len(map);
    vert_num = str_max_len(map);
    vert = (t_line **)malloc(sizeof(t_line *) * (vert_num + 1));
    hor = (t_line **)malloc(sizeof(t_line *) * (hor_num + 1));
    i = 0;
    while (map[i])
    {

    }
    return (0);
}