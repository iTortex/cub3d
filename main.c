#include "cub3d.h"

void	check_res(t_file *file)
{
	if (file->win.height == 0 || file->win.width == 0)
	{
		write(2, "REOSLUTION ERROR\n", 16);
		exit(0);
	}
	if (file->sides.west == NULL || file->sides.north == NULL ||
	file->sides.east == NULL || file->sides.south == NULL)
	{
		write(2, "SIDES ERROR\n", 11);
		exit(0);
	}
	if (file->color.chc == 0 || file->color.chf == 0)
	{
		write(2, "COLOR ERROR\n", 12);
		exit(0);
	}
}

void	init(t_file *file)
{
	file->win.height = 0;
	file->win.width = 0;
	file->sides.south = NULL;
	file->sides.north = NULL;
	file->sides.east = NULL;
	file->sides.west = NULL;
	file->color.chc = 0;
	file->color.chf = 0;

}

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
	init(&file);
	file.first = NULL;
	if (!(file.fd = open(argv[1], O_RDONLY)))
		return (0);
	while (get_next_line(file.fd, &file.line) > 0)
	{
		pars(&file);
	}
	check_res(&file);
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