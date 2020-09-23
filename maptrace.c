#include "cub3d.h"

void	maptrace(t_file *file)
{
	if (file->color.chc == 0 || file->color.chf == 0)
	{
		write(2, "COLOR ERROR\n", 12);
		exit(0);
	}
	file->stop_map = 1;
	// printf("%s\n", file->line);
	ft_lstadd_back(&file->first, ft_lstnew(file->line));
}