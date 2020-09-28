#include "cub3d.h"

static void	is_it_map(t_file *file)
{
	int j;

	j = 0;
	while (file->line[j] == ' ')
		j++;
	if (file->line[j] == '\0')
	{
		write(2, "DATA ERROR\n", 11);
		exit(0);
	}
	while (file->line[j] == '1' || file->line[j] == '0' ||
	file->line[j] == ' ' || file->line[j] == '2' || file->line[j] == 'N' ||
	file->line[j] == 'S' || file->line[j] == 'W' || file->line[j] == 'E')
		j++;
	if (file->line[j] == '\0')
		maptrace(file);
	else
	{
		write(2, "DATA ERROR\n", 11);
		exit(0);
	}
}

void	look_for_map(t_file *file)
{
	if (*file->line == '\0' && file->stop_map == 0)
	{
		free(file->line);
		return;
	}
	if (*file->line == '\0' && file->stop_map == 1)
	{
		write(2, "DATA ERROR\n", 11);
		exit(0);
	}
	is_it_map(file);
	// if (file->line)
	// 	free(file->line);
}