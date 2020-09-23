#include "cub3d.h"

void	inv_file(void)
{
	write(2, "INVALID FILE\n", 13);
	exit(0);
}


void	check_res(t_file *file)
{
	if (file->win.height == 0 || file->win.width == 0)
		inv_file();
	if (file->sides.west == NULL || file->sides.north == NULL ||
	file->sides.east == NULL || file->sides.south == NULL)
		inv_file();
	if (file->color.chc == 0 || file->color.chf == 0)
		inv_file();
	if (file->stop_map == 0)
		inv_file();
	
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
	file->sprite = NULL;
	file->stop_map = 0;
	file->stop_gamer = 0;
	file->first = NULL;
}

int	main(int argc, char **argv)
{
	t_file	file;
	char *check;

	if (argc != 2 && argc != 3)
		inv_file();
	check = ft_substr(argv[1], ft_strlen(argv[1]) - 4, ft_strlen(argv[1]));
	if (ft_strnstr(check, ".cub", ft_strlen(argv[1])) == NULL)
		inv_file();
	free(check);
	if (argc == 3)
		file.bmp_check = ft_strdup(argv[2]);
	init(&file);
	if (!(file.fd = open(argv[1], O_RDONLY)))
		inv_file();
	while (get_next_line(file.fd, &file.line) > 0)
	{
		if (pars(&file) == 1)
			break;
	}
	check_res(&file);
	maptrace(&file);
	look_for_map(&file);
	onlymap(&file);
	flood_fill(&file);
	cub3d(&file);
	return (0);
}