#include "cub3d.h"


void	win(t_file *file)
{
	char **win;

	win = ft_split(file->line, ' ');
	if (ft_strlen(win[0]) > 1)
	{
		write(2, "RESLUTION ERROR\n", 16);
		exit(0);
	}
	res_error(win);
	file->win.width = ft_atoi(win[1]);
	file->win.height = ft_atoi(win[2]);
	free(win);
	if (file->win.width < 1 || file->win.height < 1)
	{
		write(2, "RESLUTION ERROR\n", 16);
		exit(0);
	}
	if (file->win.height > 1080)
		file->win.height = 1080;
	if (file->win.width > 1920)
		file->win.width = 1920;
}

void	timeforif(t_file *file)
{
	char **side;

	file->line = ft_strtrim(file->line, " ");
	side = ft_split(file->line, ' ');
	if (*file->line == 'R')
		win(file);
	if (*file->line == 'F' || *file->line == 'C')
		get_color(file);
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
	if (i == 0)
		return ;
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
	if (ft_strnstr(file->line, "1", 1))
		maptrace(file);
}