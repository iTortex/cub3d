#include "cub3d.h"

void	res_er(void)
{
	write(2, "RESLUTION ERROR\n", 16);
	exit(0);
}

void	win(t_file *file)
{
	char **win;

	mlx_get_screen_size(file->img.mlx, &file->win.pc_width, &file->win.pc_height);
	if (file->win.width != 0 || file->win.height != 0)
		res_er();
	win = ft_split(file->line, ' ');
	if (ft_strlen(win[0]) > 1)
		res_er();
	res_error(win);
	file->win.width = ft_atoi(win[1]);
	file->win.height = ft_atoi(win[2]);
	lets_free(win);
	free(win);
	if (file->win.width < 1 || file->win.height < 1)
		res_er();
	if (file->win.height > file->win.pc_height)
		file->win.height = file->win.pc_height;
	if (file->win.width > file->win.pc_width)
		file->win.width = file->win.pc_width;
}

void	timeforif(t_file *file)
{
	char **side;
	char *ptr;

	ptr = file->line;
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
	ft_strnstr(side[0], "S", 1) != NULL)
		makeside(file);
	free(ptr);
	free(file->line);
	lets_free(side);
	free(side);
}

int	pars(t_file *file)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(file->line);
	if (i == 0 && file->stop_map == 1)
	{
		free(file->line);
		// while (get_next_line(file->fd, &file->line) > 0)
		// {
		// 	if (*file->line != '\0')
		// 	{
		// 		write(2, "INVALID FILE\n", 13);
		// 		exit(0);
		// 	}
		// }
		return (1);
	}
	if (i == 0 && file->stop_map == 0)
	{
		free(file->line);
		return (0);
	}
	if (ft_strnstr(file->line, "S", i) != NULL && file->sprite != NULL &&
	file->sides.south != NULL)
		look_for_map(file);
	if (ft_strnstr(file->line, "NO", i) != NULL ||
	ft_strnstr(file->line, "SO", i) != NULL ||
	ft_strnstr(file->line, "WE", i) != NULL ||
	ft_strnstr(file->line, "EA", i) != NULL ||
	ft_strnstr(file->line, "C", i) != NULL ||
	ft_strnstr(file->line, "R", i) != NULL ||
	ft_strnstr(file->line, "F", i) != NULL ||
	ft_strnstr(file->line, "S", i) != NULL)
		timeforif(file);
	else
		 look_for_map(file);
	return (0);
}