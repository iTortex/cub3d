#include "cub3d.h"

void	maptrace(t_file *file)
{
	ft_lstadd_back(&file->first, ft_lstnew(file->line));
	// printf("%s\n", file->line);
}