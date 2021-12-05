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
void fractal_drawing(t_data *data)
{
    double column = 0;
    double row = 0;
    int iteration = 0;

    while (row < HEIGHT)
    {
        column = 0;
        while (column < WIDTH)
        {
            iteration = mandelbrot(data, column, row);
            if (iteration >= MAX_ITERATION)
                my_mlx_pixel_put(data, column, row, 0x00FFFFFF);
            else
                my_mlx_pixel_put(data, column, row, 0x000000FF * iteration / 10);
            column++;
        }
        row++;
    }
}

int mandelbrot(t_data *data, int column, int row)
{
    double x = 0, y = 0;
    int iteration = 0;
    // my_mlx_pixel_put(data, column, row, 0x000000FF + iteration++ % 256 ); GRADIENT
    //  Convert pixel coordinate to complex number
    double c_re = (column - WIDTH / 2.0) * 4.0 / WIDTH; // подгон картинки под радиус 2 вне зависимости от рамзера окна //x
    double c_im = (row - HEIGHT / 2.0) * 4.0 / WIDTH;   // y
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
    return(iteration);
}


	//if (key == MOUSE_UP_SCRLL)
	//	zoom_in(x, y, f);
	//if (key == MOUSE_DOWN_SCRLL)
	//	zoom_out(x, y, f);