#include "cub3d.h"

void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    unsigned int    *dst;

    dst = data->data + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}


void	writepixel(t_img img, int i, int j)
{
	int x = 0;
	int y = 0;

	while (y < 16)
	{
		x = 0;
		while(x < 16)
		{
			my_mlx_pixel_put(&img, x + i, y + j, 0x00ffffff);
			x++;
		}
		y++;
	}
}

// void	make_map(t_file *file)
// {
// 	int i;
// 	int j;

// 	j = 0;
// 	i = ft_lstsize(file->first);
// 	file->map = ft_calloc(i + 1, sizeof(char **));
// 	while (j != i)
// 	{
// 		// printf("%s\n", file->first->content);
// 		file->map[j] = ft_strdup(file->first->content);
// 		ft_bzero(file->first->content, ft_strlen(file->first->content));
// 		free(file->first->content);
// 		file->first = file->first->next;
// 		j++;
// 	}

// }

// int     closes(void)
// {
//     exit(1);
//     return (0);
// }

void     cub3d(t_file *file)
{
    int x;
    int y;
	// double c = 0;
	// double ii = 0;
	// double jj = 0;
    // unsigned int color;
    // t_data img;

    x = 0;
    y = 0;
    file->clr = 0x00d0000f;
    file->img.mlx = mlx_init();
    file->img.mlx_win = mlx_new_window(file->img.mlx, file->win.width, file->win.height, "Ya rodilsa");
    file->img.img = mlx_new_image(file->img.mlx, file->win.width, file->win.height);
    file->img.data = (unsigned int *)mlx_get_data_addr(file->img.img, &file->img.bpp, &file->img.line_length, &file->img.endian);
	// mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
	// engine(file);
	// make_map(file);
	new_slide(file);
	// img.xpm = mlx_xpm_file_to_image (img.mlx, "image.xpm", &x, &y);
	// mlx_put_image_to_window(img.mlx,img.mlx_win, img.xpm, 0, 0);
    // if (file->map[y])
    // {
    //     x = 1;
	// 	double player_a = 90;
    //     if (file->map[y][x])
	// 	{
	// 		// if (file->map[y][x] == '1')
	// 		// 	writepixel(img, i, j);
			
	// 		for (int c = 0; c < 20; c += 0.05)
	// 			my_mlx_pixel_put(&img, x + c * cos(player_a), y + c * sin(player_a), 0x00ff0000);
	// // 			writepixel(img, i, j);
	// // 			// double z = 0.05;
	// // 			// double cameraX = 2 * z / file->win.lenght - 1;
	// // 			// writepixel(img, (-1 + 2 * cameraX) + i, (1 + 0.66 * cameraX) + j);
	// // 			for(double z = 0; z < file->win.lenght; z += 0.05)
	// // 			{
	// // 				double cameraX = 2 * z / file->win.lenght - 1;
	// // 				my_mlx_pixel_put(&img, (0 + 2 * cameraX) * i,(1 + 0.66 * cameraX) * j, 0x00ffff00);
	// // 				// writepixelp(img, (-1 + 2 * cameraX) * i, (1 + 0.66 * cameraX) * j);
	// // 				// int mapx = (int)(-1 + 2 * cameraX) + i;
	// // 				// int mapy = (int)(1 + 0.66 * cameraX) + j;
	// // 				// if (file->map[mapy][mapx] == '0' || file->map[mapy][mapx])
	// // 				// 	break;
	// // 			}
	// // 		i += 16;
	// // 			// my_mlx_pixel_put(&img, x, y, color);
	// // 		x++;
	//  	}
	// // // 	j += 16;
	// // 	y++;
    // }
    // mlx_put_image_to_window(file->img.mlx, file->img.mlx_win, file->img.img, 0, 0);
    // mlx_hook(file->img.mlx_win, 17, 0, closes, &file->img);
    
	// mlx_loop(file->img.mlx);
} 