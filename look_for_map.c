#include "cub3d.h"

void	is_it_map(t_file *file, int j)
{
	if (file->line[j] == '\0')
		return ;
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
	int i;

	i = 0;
	while ((file->line[i] >= 9 && file->line[i] <= 13) || file->line[i] == ' ')
		i++;
	if (file->line[i] == '0' || file->line[i] == '1' || file->line[i] == 'S')
		is_it_map(file, i);
	else
	{
		write(2, "DATA ERROR\n", 11);
		exit(0);
	}
}