/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:36:48 by dleaves           #+#    #+#             */
/*   Updated: 2021/12/14 23:13:40 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_data *data, int row, int column)
{
	double	x;
	double	y;
	double	x_tmp;
	int		iteration;

	data->x_re = ((row + data->x_offset * data->zoom)
			/ data->zoom - WIDTH / 2.0) * 4 / WIDTH + data->x_pixel;
	data->y_im = ((column + data->y_offset * data->zoom)
			/ data->zoom - HEIGHT / 2.0) * 4 / WIDTH + data->y_pixel;
	x = 0;
	y = 0;
	iteration = 0;
	while (x * x + y * y <= 4 && iteration < MAX_ITERATION)
	{
		x_tmp = x * x - y * y + data->x_re;
		y = 2.0 * x * y + data->y_im;
		x = x_tmp;
		iteration++;
	}
	return (iteration);
}

int	julia(t_data *data, int row, int column)
{
	double	x_re;
	double	y_im;
	double	x_tmp;
	int		iteration;

	x_re = ((row + data->x_offset * data->zoom)
			/ data->zoom - WIDTH / 2.0) * 4 / WIDTH + data->x_pixel;
	y_im = ((column + data->y_offset * data->zoom)
			/ data->zoom - HEIGHT / 2.0) * 4 / WIDTH + data->y_pixel;
	iteration = 0;
	while (x_re * x_re + y_im * y_im <= 4.0 && iteration < MAX_ITERATION)
	{
		x_tmp = x_re * x_re - y_im * y_im + data->julia_x;
		y_im = 2.0 * x_re * y_im + data->julia_y;
		x_re = x_tmp;
		iteration++;
	}
	return (iteration);
}

int	serpinskiy(int row, int column)
{
	int	i;

	i = 0;
	row *= ZOOM_OFFSET;
	column *= ZOOM_OFFSET;
	while (i < MAX_ITERATION)
	{
		if ((row % 2 == 1) && (column % 2 == 1))
			return (0);
		row /= 2;
		column /= 2;
		i++;
	}
	return (20);
}

void	fractal_drawing(t_data *data)
{
	double	row;
	double	column;
	int		iteration;

	column = 0;
	iteration = 0;
	while (column < HEIGHT)
	{
		row = 0;
		while (row < WIDTH)
		{
			if (data->fractal == 1)
				iteration = mandelbrot(data, row, column);
			else if (data->fractal == 2)
				iteration = julia(data, row, column);
			else if (data->fractal == 3)
				iteration = serpinskiy(row, column);
			color_filling(data, iteration, row, column);
			row++;
		}
		column++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->img_ptr, 0, 0);
}
