#include "cub3d.h"

static void	mlx_error(void)
{
	write(2, "MLX ERROR\n", 10);
	exit(0);
}


static void	textures(t_file *file)
{
	if ((file->texn.img = mlx_xpm_file_to_image(file->img.mlx, file->sides.north, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	file->texn.data = (unsigned int *)mlx_get_data_addr(file->texn.img, &file->texn.bpp, &file->texn.line_length, &file->texn.endian);
	if ((file->texe.img = mlx_xpm_file_to_image(file->img.mlx, file->sides.east, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	file->texe.data = (unsigned int *)mlx_get_data_addr(file->texe.img, &file->texe.bpp, &file->texe.line_length, &file->texe.endian);
	if ((file->texw.img = mlx_xpm_file_to_image(file->img.mlx, file->sides.west, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	file->texw.data = (unsigned int *)mlx_get_data_addr(file->texw.img, &file->texw.bpp, &file->texw.line_length, &file->texw.endian);
	if ((file->texs.img = mlx_xpm_file_to_image(file->img.mlx, file->sides.south, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	file->texs.data = (unsigned int *)mlx_get_data_addr(file->texs.img, &file->texs.bpp, &file->texs.line_length, &file->texs.endian);
	if ((file->sprites.img = mlx_xpm_file_to_image(file->img.mlx, file->sprite, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	file->sprites.data = (unsigned int *)mlx_get_data_addr(file->sprites.img, &file->sprites.bpp, &file->sprites.line_length, &file->sprites.endian);
}

void     cub3d(t_file *file)
{
	file->img.mlx = NULL;
	file->img.mlx_win = NULL;
	file->img.img = NULL;
	file->img.data = NULL;

    file->img.mlx = mlx_init();
	while (file->win.height % 64 != 0)
		file->win.height++;
	while (file->win.width % 64 != 0)
		file->win.width++;
    if (!(file->img.mlx_win = mlx_new_window(file->img.mlx, file->win.width, file->win.height, "HELLO")))
		mlx_error();
    if (!(file->img.img = mlx_new_image(file->img.mlx, file->win.width, file->win.height)))
		mlx_error();
	if (!(file->img.data = (unsigned int *)mlx_get_data_addr(file->img.img, &file->img.bpp, &file->img.line_length, &file->img.endian)))
		mlx_error();
	textures(file);
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	if (file->x_max == 1)
		make_bmp(file);
	new_slide(file);
	mlx_loop(file->img.mlx);
} 