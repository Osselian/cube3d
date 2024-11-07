#include "../../incs/cub3D.h"

void	*free_arrarr(void ***arr, void (*free_func)(void *))
{
	void	***tmp;

	tmp = arr;
	while (*arr)
	{
		free_arr(*arr, free_func);
		arr++;
	}
	free(tmp);
	return (NULL);
}
