#include "cub3d.h"

int	main(void)
{
	// const char *flgs;
	// const char *map;
	int	fd;
	t_file	file;

	if (!(fd = open("map.txt", O_RDONLY)))
		return (0);
	while (get_next_line(fd, &file.line))
	{
		pars(&file);
	}
	return (0);
}