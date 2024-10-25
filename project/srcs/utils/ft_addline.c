#include "../../incs/cub3D.h"

int	ft_addline(char **arr, char *ln, unsigned int *maplen)
{
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	arr = ft_realloc(arr, *maplen + 1);
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	arr[*maplen] = ft_strdup(ft_strtrim(ln, "\n"));
	printf("DEBUG arr=<%s>\n", arr[0]);
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	arr[*maplen] = ft_strdup("\0");
	(*maplen)++;
	// printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	return (0);
}
