#include "../../incs/cub3D.h"

bool	check_color(char *ln)
{
	int	i;

	i = 0;
	// printf("DEBUG %s %d LINE=<%s>\n\n", __FILE__, __LINE__, ln);
	while (ln[i] != '\0')
	{
		if (!ft_isdigit(ln[i]))
		{
			// printf("DEBUG %s %d COLOR=%c LINE=%s\n", __FILE__, __LINE__, ln[i], ln);
			print_error(INCORRECT_COLOR);
			// printf("DEBUG %s %d\n", __FILE__, __LINE__);
			return (true);
		}
		i++;
	}
	if (ft_atoi(ln) < 0 || ft_atoi(ln) > 255)
	{
		printf("DEBUG %s %d COLOR=%i\n", __FILE__, __LINE__, ft_atoi(ln));
		print_error(INCORRECT_COLOR);
		// printf("DEBUG %s %d\n", __FILE__, __LINE__);
		return (true);
	}
	// printf("DEBUG %s %d\n", __FILE__, __LINE__);
	return (false);
}
