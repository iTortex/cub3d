#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_file	file;
	char *check;

	if (argc != 2)
		return (0);
	check = ft_substr(argv[1], ft_strlen(argv[1]) - 4, ft_strlen(argv[1]));
	if (ft_strnstr(check, ".cub", ft_strlen(argv[1])) == NULL)
	{
		write(2, "INVALID FILE\n", 13);
		free(check);
		return (0);
	}
	file.first = NULL;
	if (!(file.fd = open(argv[1], O_RDONLY)))
		return (0);
	while (get_next_line(file.fd, &file.line) > 0)
	{
		pars(&file);
	}
	maptrace(&file);
	onlymap(&file);
	cub3d(&file);
	// printf("%i:%i\n", file.win.width, file.win.height);
	// printf("%i:%i:%i\n", file.color.r, file.color.g, file.color.b);
	// printf("%i\n", 'w');
	// printf("%s\n", file.sides.west);
	// printf("%s\n", file.sides.south);
	// printf("%s\n", file.sides.north);
	// printf("%s\n", file.sides.east);
	printf("%s\n", file.map[4]);
	// printf("%f\n", file.game.posx);
	// printf("%f\n", file.game.posy);
	// printf("%f\n", file.game.dirx);
	// printf("%f\n", file.game.diry);
	// printf("%f\n", file.game.planex);
	// printf("%f\n", file.game.planey);
	return (0);
}