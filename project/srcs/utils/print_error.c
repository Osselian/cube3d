
#include "../../incs/cub3D.h"

int	print_error(char *mes)
{
	write(2, "Error\n", 6);
	write(2, mes, ft_strlen(mes));
	return (1);
}
