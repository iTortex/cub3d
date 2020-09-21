#include "cub3d.h"

void	write_error(void)
{
	write(2, "COLOR ERROR\n", 12);
	exit(0);
}

void	color_size(t_file *file)
{
	if (file->color.rf < 0 || file->color.rf > 255 || file->color.gf < 0 ||
	file->color.gf > 255 || file->color.bf < 0 || file->color.bf > 255 ||
	file->color.rc > 255 || file->color.rc < 0 || file->color.gc > 255 ||
	file->color.gc < 0 || file->color.bc < 0 || file->color.bc > 255)
		write_error();
}

void	put_color(t_file *file, char **color)
{
	if (*file->line == 'F' && file->color.chf == 0)
	{
		file->color.chf = 1;
		file->color.rf = ft_atoi(color[0]);
		file->color.gf = ft_atoi(color[1]);
		file->color.bf = ft_atoi(color[2]);
	}
	else if (*file->line == 'C' && file->color.chc == 0)
	{
		file->color.chc = 1;
		file->color.rc = ft_atoi(color[0]);
		file->color.gc = ft_atoi(color[1]);
		file->color.bc = ft_atoi(color[2]);
	}
	else
		write_error();
	color_size(file);
	file->color.clrf = (file->color.rf << 16);
	file->color.clrf = file->color.clrf | (file->color.gf << 8);
	file->color.clrf = file->color.clrf | (file->color.bf);
	file->color.clrc = (file->color.rc << 16);
	file->color.clrc = file->color.clrc | (file->color.gc << 8);
	file->color.clrc = file->color.clrc | (file->color.bc);
}

void	color_error(char **color)
{
	int i;
	int	j;
	int x;

	i = 0;
	j = 0;
	x = 0;
	while (color[i])
		i++;
	if (i != 3)
		write_error();
	i = 0;
	color[0] = ft_strtrim(color[0], " ");
	color[1] = ft_strtrim(color[1], " ");
	color[2] = ft_strtrim(color[2], " ");
	while ((color[0][i] >= '0' && color[0][i] <= '9') || color[0][i] == '-')
		i++;
	while ((color[1][j] >= '0' && color[1][j] <= '9') || color[1][j] == '-')
		j++;
	while ((color[2][x] >= '0' && color[2][x] <= '9') || color[2][x] == '-')
		x++;
	if (color[0][i] != '\0' || color[1][j] != '\0' || color[2][x] != '\0')
		write_error();
}

void 	get_color(t_file *file)
{
	char **color;
	char *ptr;
	int i;
	int y;
	
	y = 0;
	i = 0;
	while(file->line[y])
	{
		if (file->line[y] == ',' || file->line[y] == '-')
			i++;
		y++;
	}
	if (i != 2)
		write_error();
	i = 1;
	if ((file->line[0] == 'F' || file->line[0] == 'C') && 
	file->line[1] != ' ')
		write_error();
	while (file->line[i] > '9' || file->line[i] < '0')
		i++;
	ptr = (&((char *)file->line)[i]);
	color = ft_split(ptr, ',');
	// free(color);
	color_error(color);
	put_color(file, color);
}