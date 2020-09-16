#include "cub3d.h"

void	maptrace(t_file *file)
{
	ft_lstadd_back(&file->first, ft_lstnew(file->line));
	// while (get_next_line(file->fd, &file->line) > 0)
	// 	maptrace(file);
	// if (get_next_line(file->fd, &file->line) == 0)
	// {
	// 	ft_lstadd_back(&file->first, ft_lstnew(file->line));
	// 	return ;
	// }
	// ft_lstadd_back(&file->first, ft_lstnew(file->line));
	// printf("%s\n", file->line);
}