#include "cub3d.h"

int	*keys(t_file *file)
{
	mlx_new_image(file->img.mlx, file->win.width, file->win.height);
	file->game.posx -= 0.05;
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	return (0);
}

int     closes(void)
{
    exit(1);
    return (0);
}

void	new_slide(t_file *file)
{
	file->img.img = mlx_new_image(file->img.mlx, file->win.width, file->win.height);
    file->img.data = (unsigned int *)mlx_get_data_addr(file->img.img, &file->img.bpp, &file->img.line_length, &file->img.endian);
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
    mlx_hook(file->img.mlx_win, 17, 0, closes, &file->img);
	mlx_key_hook(file->img.mlx_win, keys(file), 119);
    mlx_loop(file->img.mlx);
}