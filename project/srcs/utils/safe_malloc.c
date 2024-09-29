#include "../../incs/cub3D.h"

void	*safe_malloc(size_t str)
{
	void	*result;

	result = malloc(str);
	if (result == NULL)
		print_error("Error with the malloc\n");
	ft_bzero(result, str);
	return (result);
}
