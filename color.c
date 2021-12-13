#include "fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
    char *dst;

    dst = data->addr_ptr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = colour;
}

void color_filling(t_data *data, int iteration, int column, int row)
{   



    if (data->color_shift == 0)
    {
        if (iteration >= MAX_ITERATION)
            my_mlx_pixel_put(data, column, row, 0xFFFFFF);
        else
            my_mlx_pixel_put(data, column, row, 0x0000FF * iteration / 10);
    }
    if (data->color_shift == 1)
    {
        if (iteration >= MAX_ITERATION)
            my_mlx_pixel_put(data, column, row, 0xffefd5);
        else
            my_mlx_pixel_put(data, column, row, 0x483d8b * iteration / 10);
    }
    if (data->color_shift == 2)
    {
        if (iteration >= MAX_ITERATION)
            my_mlx_pixel_put(data, column, row, 0xf0fff0);
        else
            my_mlx_pixel_put(data, column, row, 0xffebcd * iteration / 10);
    }
    if (data->color_shift == 3)
    {
        if (iteration >= MAX_ITERATION)
            my_mlx_pixel_put(data, column, row, 0xe6e6fa);
        else
            my_mlx_pixel_put(data, column, row, 0x8b4513 * iteration / 10);
    }
}

void change_color(int keycode, t_data *data)
{
    if (keycode == ONE)
        data->color_shift = 1;
    if (keycode == TWO)
        data->color_shift = 2;
    if (keycode == THREE)
        data->color_shift = 3;
}