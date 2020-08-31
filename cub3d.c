#include "cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    unsigned int    *dst;

    dst = data->data + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

int     closes(void)
{
    exit(1);
    return (0);
}

int     main(void)
{
    unsigned int x;
    unsigned int y;
    unsigned int color;
    t_data img;

    x = 0;
    y = 0;
    color = 0x00ffffff;
    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(img.mlx, 960, 540);
    img.data = (unsigned int *)mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
    while (y++ < 539)
    {
        x = 0;
        while (x++ < 959)
            my_mlx_pixel_put(&img, x, y, color);
        if (color == 0x00ff0000 && y >= 360)
            color = 0x00ffffff;
        if (y % 180 == 0)
            color = color & 0x00ff0000;
    }
    mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 1, 539);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 959, 1);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 1, 1);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 960, 540);
    mlx_hook(img.mlx_win, 17, 0, closes, &img);
    mlx_loop(img.mlx);
} 