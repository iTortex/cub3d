#include "cub3d.h"

int	main(void)
{
	// const char *flgs;
	// const char *map;
	t_file	file;

	file.first = NULL;
	if (!(file.fd = open("map.txt", O_RDONLY)))
		return (0);
	while (get_next_line(file.fd, &file.line) > 0)
	{
		pars(&file);
	}
	onlymap(&file);
	//cub3d(&file);
	printf("%i:%i\n", file.win.width, file.win.height);
	printf("%i:%i:%i\n", file.color.r, file.color.g, file.color.b);
	printf("%i\n", 'w');
	printf("%s\n", file.sides.west);
	printf("%s\n", file.sides.south);
	printf("%s\n", file.sides.north);
	printf("%s\n", file.sides.east);
	printf("%s\n", file.sprite);
	printf("%f\n", file.game.posx);
	printf("%f\n", file.game.posy);
	printf("%f\n", file.game.dirx);
	printf("%f\n", file.game.diry);
	printf("%f\n", file.game.planex);
	printf("%f\n", file.game.planey);
	return (0);
}