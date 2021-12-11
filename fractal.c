#include "fractol.h"
#include <stdio.h>

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

int mandelbrot(t_data *data, int column, int row)
{
    double x;
    double y;
    double x_re;
    double y_im;
    double x_tmp;
    int iteration;

    //  Convert pixel coordinate to complex number
    x_re = ((column + data->x_offset * data->zoom) / data->zoom - WIDTH / 2.0) * 4 / WIDTH; // -0.5 - смещение вправо подгон картинки ///под радиус 2 вне зависимости от рамзера окна //x
    y_im = ((row + data->y_offset * data->zoom) / data->zoom - HEIGHT / 2.0) * 4 / WIDTH;   // +0,5 смещение вверх (y)
    x = 0;
    y = 0;
    iteration = 0;
    while (x * x + y * y <= 4 && iteration < MAX_ITERATION)
    {
        x_tmp = x * x - y * y + x_re;
        y = 2.0 * x * y + y_im;
        x = x_tmp;
        iteration++;
    }
    return (iteration);
}

void fractal_drawing(t_data *data)
{
    double column;
    double row;
    int iteration;

    row = 0;
    iteration = 0;
    while (row < HEIGHT)
    {
        column = 0;
        while (column < WIDTH)
        {
            if (data->fractal == 1)
                iteration = mandelbrot(data, column, row);
            else if (data->fractal == 2)
                iteration = mandelbrot(data, column, row); // change to Julia
            color_filling(data, iteration, column, row);
            column++;
        }
        row++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->img_ptr, 0, 0);
}