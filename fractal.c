#include "fractol.h"
//#include <stdio.h>

int mandelbrot(t_data *data, int column, int row)
{
    double x;
    double y;
    double x_re;
    double y_im;
    double x_tmp;
    int iteration;

    //  Convert pixel coordinate to complex number
    x_re = ((column + data->x_offset * data->zoom) / data->zoom  - WIDTH / 2.0) * 4 / WIDTH + data->x_pixel; // -0.5 - смещение вправо подгон картинки ///под радиус 2 вне зависимости от рамзера окна //x
    y_im = ((row + data->y_offset * data->zoom) / data->zoom - HEIGHT / 2.0) * 4 / WIDTH + data->y_pixel;   // +0,5 смещение вверх (y)
    //printf("x_re: %f y_im: %f\n", x_re, y_im);
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

int julia(t_data *data, int column, int row)
{
    double x;
    double y;
    double x_re;
    double y_im;
    double x_tmp;
    int iteration;

    //  Convert pixel coordinate to complex number
    x_re = ((column + data->x_offset * data->zoom) / data->zoom  - WIDTH / 2.0) * 4 / WIDTH + data->x_pixel; // -0.5 - смещение вправо подгон картинки ///под радиус 2 вне зависимости от рамзера окна //x
    y_im = ((row + data->y_offset * data->zoom) / data->zoom - HEIGHT / 2.0) * 4 / WIDTH + data->y_pixel;   // +0,5 смещение вверх (y)
    //printf("x_re: %f y_im: %f\n", x_re, y_im);
    x = x_re;
    y = y_im;
    iteration = 0;
    while (x * x + y * y <= 4.0 && iteration < MAX_ITERATION)
    {
        x_tmp = x * x - y * y - 0.7;
        y = 2.0 * x * y - 0.3;
        x = x_tmp;
        iteration++;
    }
    return (iteration);
}

int		sierpinski_carpet(t_data *data, int x, int y)
{
	int i;

	i = 0;
	x *= ZOOM_OFFSET;
	y *= ZOOM_OFFSET;
	while (i < MAX_ITERATION)
	{
		if ((x % 3 == 1) && (y % 3 == 1))
			return (0);
		x /= 3;
		y /= 3;
		i++;
	}
	return (20);
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
                iteration = julia(data, column, row);
            else if (data->fractal == 3)
                iteration = sierpinski_carpet(data, column, row);
            color_filling(data, iteration, column, row);
            column++;
        }
        row++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->img_ptr, 0, 0);
}