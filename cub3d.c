#include "cub3d.h"

void	mlx_error(void)
{
	write(2, "MLX ERROR\n", 10);
	exit(0);
}

// void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
//     unsigned int    *dst;

//     dst = data->data + (y * data->line_length + x * (data->bpp / 8));
//     *(unsigned int*)dst = color;
// }


// void	writepixel(t_img img, int i, int j)
// {
// 	int x = 0;
// 	int y = 0;

// 	while (y < 16)
// 	{
// 		x = 0;
// 		while(x < 16)
// 		{
// 			my_mlx_pixel_put(&img, x + i, y + j, 0x00ffffff);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	textures(t_file *file)
{
	if ((file->texn.img = mlx_xpm_file_to_image(file->img.mlx, file->sides.north, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	free(file->sides.north);
	file->texn.data = (int *)mlx_get_data_addr(file->texn.img, &file->texn.bpp, &file->texn.line_length, &file->texn.endian);
	if ((file->texe.img = mlx_xpm_file_to_image(file->img.mlx, file->sides.east, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	free(file->sides.east);
	file->texe.data = (int *)mlx_get_data_addr(file->texe.img, &file->texe.bpp, &file->texe.line_length, &file->texe.endian);
	if ((file->texw.img = mlx_xpm_file_to_image(file->img.mlx, file->sides.west, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	free(file->sides.west);
	file->texw.data = (int *)mlx_get_data_addr(file->texw.img, &file->texw.bpp, &file->texw.line_length, &file->texw.endian);
	if ((file->texs.img = mlx_xpm_file_to_image(file->img.mlx, file->sides.south, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	free(file->sides.south);
	file->texs.data = (int *)mlx_get_data_addr(file->texs.img, &file->texs.bpp, &file->texs.line_length, &file->texs.endian);
	if ((file->sprites.img = mlx_xpm_file_to_image(file->img.mlx, file->sprite, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	free(file->sprite);
	file->sprites.data = (int *)mlx_get_data_addr(file->sprites.img, &file->sprites.bpp, &file->sprites.line_length, &file->sprites.endian);
}

void     cub3d(t_file *file)
{
	file->img.mlx = NULL;
	file->img.mlx_win = NULL;
	file->img.img = NULL;

    file->img.mlx = mlx_init();
	while (file->win.height % 64 != 0)
		file->win.height++;
	while (file->win.width % 64 != 0)
		file->win.width++;
    if (!(file->img.mlx_win = mlx_new_window(file->img.mlx, file->win.width, file->win.height, "Ya rodilsa")))
		mlx_error();
    if (!(file->img.img = mlx_new_image(file->img.mlx, file->win.width, file->win.height)))
		mlx_error();
	if (!(file->img.data = (int *)mlx_get_data_addr(file->img.img, &file->img.bpp, &file->img.line_length, &file->img.endian)))
		mlx_error();
	textures(file);
	printf("%d\n", file->map_size_y);
	engine(file);
	printf("aaaa\n");
	printf("data: %p\n", file->img.data);
	printf("img: %p\n", file->img.img);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	new_slide(file);
		// sleep(5);
	printf("AAAAA\n");
	printf("mlx: %p\n", file->img.mlx);
	mlx_loop(file->img.mlx);
} 