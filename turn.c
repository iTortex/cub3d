#include "cub3d.h"

void	turn_right(t_file *file)
{
	mlx_clear_window(file->img.mlx, file->img.mlx_win);
	mlx_new_image(file->img.mlx, file->win.width, file->win.height);
	file->game.dirx = file->game.dirx * cos(-0.1) - file->game.diry * sin(-0.1);
	file->game.diry = file->game.dirx * sin(-0.1) + file->game.diry * cos(-0.1);
	file->game.raydirx = file->game.raydirx * cos(-0.1) - file->game.raydiry * sin(-0.1);
	file->game.raydiry = file->game.raydirx * sin(-0.1) + file->game.raydiry * cos(-0.1);
	file->game.planex = file->game.planex * cos(-0.1) - file->game.planey * sin(-0.1);
	file->game.planey = file->game.planex * sin(-0.1) + file->game.planey * cos(-0.1);
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	mlx_do_sync(file->img.mlx);
	mlx_loop(file->img.mlx);
}

void	turn_left(t_file *file)
{
	mlx_clear_window(file->img.mlx, file->img.mlx_win);
	mlx_new_image(file->img.mlx, file->win.width, file->win.height);
	file->game.dirx = file->game.dirx * cos(0.1) - file->game.diry * sin(0.1);
	file->game.diry = file->game.dirx * sin(0.1) + file->game.diry * cos(0.1);
	file->game.raydirx = file->game.raydirx * cos(0.1) - file->game.raydiry * sin(0.1);
	file->game.raydiry = file->game.raydirx * sin(0.1) + file->game.raydiry * cos(0.1);
	file->game.planex = file->game.planex * cos(0.1) - file->game.planey * sin(0.1);
	file->game.planey = file->game.planex * sin(0.1) + file->game.planey * cos(0.1);
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	mlx_do_sync(file->img.mlx);
	mlx_loop(file->img.mlx);
}

void	turn(int key, t_file *file)
{
	if (key == 123)
		turn_left(file);
	if (key == 124)
		turn_right(file);
}