#include "cub3d.h"

void	w_move(t_file *file)
{
	mlx_clear_window(file->img.mlx, file->img.mlx_win);
	mlx_new_image(file->img.mlx, file->win.width, file->win.height);
	if (file->map[(int)(file->game.posx + file->game.dirx * 0.1)][(int)(file->game.posy)] != '1')
		file->game.posx += file->game.dirx * 0.1;
	if (file->map[(int)(file->game.posx)][(int)(file->game.posy + file->game.diry * 0.1)] != '1')
		file->game.posy += file->game.diry * 0.1;
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	mlx_do_sync(file->img.mlx);
	mlx_loop(file->img.mlx);
}

void	s_move(t_file *file)
{
	mlx_clear_window(file->img.mlx, file->img.mlx_win);
	mlx_new_image(file->img.mlx, file->win.width, file->win.height);
	if (file->map[(int)(file->game.posx - file->game.dirx * 0.1)][(int)(file->game.posy)] != '1')
		file->game.posx -= file->game.dirx * 0.1;
	if (file->map[(int)(file->game.posx)][(int)(file->game.posy - file->game.diry * 0.1)] != '1')
		file->game.posy -= file->game.diry * 0.1;
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	mlx_do_sync(file->img.mlx);
	mlx_loop(file->img.mlx);
}

void	a_move(t_file *file)
{
	mlx_clear_window(file->img.mlx, file->img.mlx_win);
	mlx_new_image(file->img.mlx, file->win.width, file->win.height);
	if (file->map[(int)(file->game.posx - file->game.diry * 0.1)][(int)(file->game.posy)] != '1')
		file->game.posx -= file->game.diry * 0.1;
	if (file->map[(int)(file->game.posx)][(int)(file->game.posy + file->game.dirx * 0.1)] != '1')
		file->game.posy += file->game.dirx * 0.1;
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	mlx_do_sync(file->img.mlx);
	mlx_loop(file->img.mlx);
}

void	d_move(t_file *file)
{
	mlx_clear_window(file->img.mlx, file->img.mlx_win);
	mlx_new_image(file->img.mlx, file->win.width, file->win.height);
	if (file->map[(int)(file->game.posx - file->game.diry * 0.1)][(int)(file->game.posy)] != '1')
		file->game.posx += file->game.diry * 0.1;
	if (file->map[(int)(file->game.posx)][(int)(file->game.posy - file->game.dirx * 0.1)] != '1')
		file->game.posy -= file->game.dirx * 0.1;
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	mlx_do_sync(file->img.mlx);
	mlx_loop(file->img.mlx);
}

int wasd(int key, t_file *file)
{
	if (key == 13)
		w_move(file);
	if (key == 1)
		s_move(file);
	if (key == 0)
		a_move(file);
	if (key == 2)
		d_move(file);
	if (key == 124 || key == 123)
		turn(key, file);
	if (key == 53)
	{
		mlx_clear_window(file->img.mlx, file->img.mlx_win);
    	exit(1);
	}
    return (0);
}
