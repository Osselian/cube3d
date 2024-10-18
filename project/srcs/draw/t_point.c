#include "cub3D.h"

t_point	pos_sub(const t_point a, const t_point b)
{
	t_point	res;
	
	res.x = a.x - b.x;
	res.y = a.y - b.y;
	return (res);
}

t_point	pos_sum(const t_point a, const t_point b)
{
	t_point	res;
	
	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}
