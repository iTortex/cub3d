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
	if (*file->line == 'F')
	{
		file->color.rf = ft_atoi(color[0]);
		file->color.gf = ft_atoi(color[1]);
		file->color.bf = ft_atoi(color[2]);
	}
	if (*file->line == 'C')
	{
		file->color.rc = ft_atoi(color[0]);
		file->color.gc = ft_atoi(color[1]);
		file->color.bc = ft_atoi(color[2]);
	}
	file->color.clrf = (file->color.rf << 16);
	file->color.clrf = file->color.clrf | (file->color.gf << 8);
	file->color.clrf = file->color.clrf | (file->color.bf);
	file->color.clrc = (file->color.rc << 16);
	file->color.clrc = file->color.clrc | (file->color.gc << 8);
	file->color.clrc = file->color.clrc | (file->color.bc);
}

void	win(t_file *file)
{
	char **win;

	win = ft_split(file->line, ' ');
	file->win.width = ft_atoi(win[1]);
	file->win.height = ft_atoi(win[2]);
	free(win);
}

void	timeforif(t_file *file)
{
	char **side;

	file->line = ft_strtrim(file->line, " ");
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
	free(side);
}

void	pars(t_file *file)
{
	int i;
	char *ptr;

	i = ft_strlen(file->line);
	ptr = ft_strnstr(file->line, "S", i);
	if (ft_strnstr(file->line, "NO", i) == NULL ||
	ft_strnstr(file->line, "SO", i) == NULL ||
	ft_strnstr(file->line, "WE", i) == NULL ||
	ft_strnstr(file->line, "EA", i) == NULL ||
	ft_strnstr(file->line, "C", i) == NULL ||
	ft_strnstr(file->line, "R", i) == NULL ||
	ft_strnstr(file->line, "F", i) == NULL ||
	ptr == NULL)
		timeforif(file);
	// printf("%s\n", file->line);
	if (ft_strnstr(file->line, "1", 1))
		maptrace(file);
}