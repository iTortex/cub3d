#include "cub3d.h"

int		keys(int key, t_file *file)
{
	if (key == 13)
	{
		mlx_clear_window(file->img.mlx, file->img.mlx_win);
		mlx_new_image(file->img.mlx, file->win.width, file->win.height);
		file->game.posy += 0.05;
		engine(file);
		mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
		mlx_loop(file->img.mlx);
	}
	if (key == 1)
	{
		mlx_clear_window(file->img.mlx, file->img.mlx_win);
		mlx_new_image(file->img.mlx, file->win.width, file->win.height);
		if (file->game.posy > 0.05)
			file->game.posy -= 0.05;
		engine(file);
		mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
		mlx_loop(file->img.mlx);
	}
	if (key == 0)
	{
		mlx_clear_window(file->img.mlx, file->img.mlx_win);
		mlx_new_image(file->img.mlx, file->win.width, file->win.height);
		if (file->game.posx > 0.05)
			file->game.posx -= 0.05;
		engine(file);
		mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
		mlx_loop(file->img.mlx);
	}
	if (key == 2)
	{
		mlx_clear_window(file->img.mlx, file->img.mlx_win);
		mlx_new_image(file->img.mlx, file->win.width, file->win.height);
		file->game.posx += 0.05;
		engine(file);
		mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
		mlx_loop(file->img.mlx);
	}

	if (key == 123)
	{
		mlx_clear_window(file->img.mlx, file->img.mlx_win);
		mlx_new_image(file->img.mlx, file->win.width, file->win.height);
		file->game.dirx = file->game.dirx * cos(0.05) - file->game.diry * sin(0.05);
		file->game.diry = file->game.dirx * sin(0.05) + file->game.diry * cos(0.05);
		file->game.raydirx = file->game.raydirx * cos(0.05) - file->game.raydiry * sin(0.05);
		file->game.raydiry = file->game.raydirx * sin(0.05) + file->game.raydiry * cos(0.05);
		file->game.planex = file->game.planex * cos(0.05) - file->game.planey * sin(0.05);
		file->game.planey = file->game.planex * sin(0.05) + file->game.planey * cos(0.05);
		engine(file);
		mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
		mlx_loop(file->img.mlx);
	}
		if (key == 124)
	{
		mlx_clear_window(file->img.mlx, file->img.mlx_win);
		mlx_new_image(file->img.mlx, file->win.width, file->win.height);
		file->game.dirx = file->game.dirx * cos(-0.05) - file->game.diry * sin(-0.05);
		file->game.diry = file->game.dirx * sin(-0.05) + file->game.diry * cos(-0.05);
		file->game.raydirx = file->game.raydirx * cos(-0.05) - file->game.raydiry * sin(-0.05);
		file->game.raydiry = file->game.raydirx * sin(-0.05) + file->game.raydiry * cos(-0.05);
		file->game.planex = file->game.planex * cos(-0.05) - file->game.planey * sin(-0.05);
		file->game.planey = file->game.planex * sin(-0.05) + file->game.planey * cos(-0.05);
		engine(file);
		mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
		mlx_loop(file->img.mlx);
	}
	else
		exit(0);
	return (0);
}

// int     closes(void)
// {
//     exit(1);
//     return (0);
// }

void	new_slide(t_file *file)
{
	// engine(file);
	// mlx_key_hook(file->img.mlx_win, keys, &file->img);
    // mlx_hook(file->img.mlx_win, 17, 1L<<0, closes, &file->img);
	mlx_hook(file->img.mlx_win, 2, 0, keys, file);
    mlx_loop(file->img.mlx);
}