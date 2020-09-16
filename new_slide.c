#include "cub3d.h"

void	new_slide(t_file *file)
{
	mlx_hook(file->img.mlx_win, 2, 0, wasd, file);
    mlx_loop(file->img.mlx);
}