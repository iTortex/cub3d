#include "cub3d.h"

static void	w_move(t_file *file, double ms)
{
	mlx_clear_window(file->img.mlx, file->img.mlx_win);
	if (file->map[(int)(file->game.posx + file->game.dirx * ms)][(int)(file->game.posy)] != '1')
		file->game.posx += file->game.dirx * ms;
	if (file->map[(int)(file->game.posx)][(int)(file->game.posy + file->game.diry * ms)] != '1')
		file->game.posy += file->game.diry * ms;
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	mlx_do_sync(file->img.mlx);
}

static void	s_move(t_file *file, double ms)
{
	mlx_clear_window(file->img.mlx, file->img.mlx_win);
	if (file->map[(int)(file->game.posx - file->game.dirx * ms)][(int)(file->game.posy)] != '1')
		file->game.posx -= file->game.dirx * ms;
	if (file->map[(int)(file->game.posx)][(int)(file->game.posy - file->game.diry * ms)] != '1')
		file->game.posy -= file->game.diry * ms;
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	mlx_do_sync(file->img.mlx);
}

static void	a_move(t_file *file, double ms)
{
	mlx_clear_window(file->img.mlx, file->img.mlx_win);
	if (file->map[(int)(file->game.posx - file->game.diry * ms)][(int)(file->game.posy)] != '1')
		file->game.posx -= file->game.diry * ms;
	if (file->map[(int)(file->game.posx)][(int)(file->game.posy + file->game.dirx * ms)] != '1')
		file->game.posy += file->game.dirx * ms;
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	mlx_do_sync(file->img.mlx);
}

static void	d_move(t_file *file, double ms)
{
	mlx_clear_window(file->img.mlx, file->img.mlx_win);
	if (file->map[(int)(file->game.posx + file->game.diry * ms)][(int)(file->game.posy)] != '1')
		(file->game.posx += file->game.diry * ms);
	if (file->map[(int)(file->game.posx)][(int)((file->game.posy) - file->game.dirx * ms)] != '1')
		file->game.posy -= file->game.dirx * ms;
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	mlx_do_sync(file->img.mlx);
}

int wasd(int key, t_file *file)
{
	double movespeed;

	movespeed = 0.2;
	if (key == 13)
		w_move(file, movespeed);
	if (key == 1)
		s_move(file, movespeed);
	if (key == 0)
		a_move(file, movespeed);
	if (key == 2)
		d_move(file, movespeed);
	if (key == 124 || key == 123)
		turn(key, file);
	if (key == 53)
	{
    	exit(0);
	}
	return(0);
}
