#include "cub3d.h"

void	makeside(t_file *file)
{
	char **sprite;
	sprite = ft_split(file->line, ' ');
	if (ft_strnstr(sprite[0], "S", 2) != NULL)
		file->sprite = ft_strdup(sprite[1]);
	if (ft_strnstr(sprite[0], "NO", 2) != NULL)
		file->sides.north = ft_strdup(sprite[1]);
	if (ft_strnstr(sprite[0], "WE", 2) != NULL)
		file->sides.west = ft_strdup(sprite[1]);
	if (ft_strnstr(sprite[0], "EA", 2) != NULL)
		file->sides.east = ft_strdup(sprite[1]);
	if (ft_strnstr(sprite[0], "SO", 2) != NULL)
		file->sides.south = ft_strdup(sprite[1]);
	free(sprite);
}

void	color(t_file *file)
{
	char **color;
	color = ft_split((file->line + 1), ',');
	file->color.r = ft_atoi(color[0]);
	file->color.g = ft_atoi(color[1]);
	file->color.b = ft_atoi(color[2]);
}

void	win(t_file *file)
{
	char **win;
	win = ft_split(file->line, ' ');
	file->win.lenght = ft_atoi(win[1]);
	file->win.width = ft_atoi(win[2]);
}

void	timeforif(t_file *file)
{
	char **side;

	side = ft_split(file->line, ' ');
	if (*file->line == 'R')
		win(file);
	if (*file->line == 'F' || *file->line == 'C')
		color(file);
	if (ft_strnstr(side[0], "NO", 2) != NULL || 
	ft_strnstr(side[0], "SO", 2) != NULL ||
	ft_strnstr(side[0], "WE", 2) != NULL ||
	ft_strnstr(side[0], "EA", 2) != NULL ||
	ft_strnstr(side[0], "S", 2) != NULL)
		makeside(file);
	
	
}

void	pars(t_file *file)
{ 
	file->line = ft_strtrim(file->line, " ");
	timeforif(file);
	printf("%i:%i\n", file->win.lenght, file->win.width);
	printf("%i:%i:%i\n", file->color.r, file->color.g, file->color.b);
	printf("%s\n", file->sides.west);
	printf("%s\n", file->sides.south);
	printf("%s\n", file->sides.north);
	printf("%s\n", file->sides.east);
	printf("%s\n", file->sprite);
}