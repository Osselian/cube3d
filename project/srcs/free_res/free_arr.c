#include "../../incs/cub3D.h"

void	*free_arr(void **arr, void (*free_func)(void *))
{
	void	**tmp;

	tmp = arr;
	while (*arr)
	{
		(*free_func)(*arr);
		arr++;
	}
	free(tmp);
	return (NULL);
}
