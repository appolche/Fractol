#include "fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
    char *dst;

    dst = data->addr_ptr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = colour;
}

void color_filling(t_data *data, int iteration, int column, int row)
{
    if (iteration >= MAX_ITERATION)
        my_mlx_pixel_put(data, column, row, 0x00FFFFFF);
    else
        my_mlx_pixel_put(data, column, row, 0x000000FF * iteration / 10);
}
