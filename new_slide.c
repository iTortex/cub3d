#include "cub3d.h"

static int		exitt(void)
{
		exit(0);
		return (0);
}

void	new_slide(t_file *file)
{
	mlx_hook(file->img.mlx_win, 2, 0, wasd, file);
	mlx_hook(file->img.mlx_win, 17, 0, exitt, file);
}