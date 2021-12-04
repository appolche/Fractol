#include "fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
    char *dst;

    dst = data->addr_ptr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = colour;
}

//вытащить цикл
//вытащить отрисовку
//оставить в манделе только вычисления 



void draw_mandelbrot (t_data *data)
{
    double column = 0;
    double row = 0;
    double x = 0, y = 0;
    int iteration = 0;

    while (row < HEIGHT)
    {
        column = 0;
        while (column < WIDTH)
        {
            //my_mlx_pixel_put(data, column, row, 0x000000FF + iteration++ % 256 ); GRADIENT
            // Convert pixel coordinate to complex number
            double c_re = (column - WIDTH / 2.0) * 4.0 / WIDTH; // подгон картинки под радиус 2 вне зависимости от рамзера окна //x
            double c_im = (row - HEIGHT / 2.0) * 4.0 / WIDTH;//y
            x = 0;
            y = 0;
            iteration = 0;
            while (x * x + y * y <= 4 && iteration < MAX_ITERATION)
            {
                double x_new = x * x - y * y + c_re;
                y = 2 * x * y + c_im;
                x = x_new;
                iteration++;
            }
            //double color = 255 - (iteration * 255 / MAX_ITERATION);
            //int color[10] = {0x00FF0000, 0x0000FF00, 0x000000FF, 0x0000FFFF, 0x00FF00FF, 0x000F00FF, 0x00F000FF, 0x000F000F, 0x0F00000F, 0x000F00F0};
            double draw = iteration / MAX_ITERATION;
            if (iteration >= MAX_ITERATION)
                my_mlx_pixel_put(data, column, row, 0x00FFFFFF);
            else
                my_mlx_pixel_put(data, column, row, 0x000000FF * iteration / 10);
            column++;
        }
        row++;
    }
}