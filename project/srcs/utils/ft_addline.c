#include "../../incs/cub3D.h"

int	ft_addline(char **arr, char *ln)
{
	int	i;

	i = 0;
	while (arr[i] && arr[i][0] != '\0')
		i++;
	arr[i] = ft_strdup(ft_strtrim(ln, "\n"));
	ft_straddchar(&arr[i], '\0');
	arr[i + 1] = ft_strdup("\0");
	return (0);
}
