#include "../../incs/cub3D.h"

int	ft_addline(char **arr, char *ln)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	arr[i] = ft_strdup(ln);
	arr[i + 1] = ft_strdup("\0");
	// printf("DEBUG %s\n",arr[i]);
	return (0);
}
