/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:43:01 by dleaves           #+#    #+#             */
/*   Updated: 2021/12/14 23:09:13 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractal_type(char *str)
{
	int	fractal_number;

	fractal_number = 0;
	if (ft_strcmp(str, "mandelbrot") == 0)
		fractal_number = 1;
	else if (ft_strcmp(str, "julia") == 0)
		fractal_number = 2;
	else if (ft_strcmp(str, "serpinskiy") == 0)
		fractal_number = 3;
	return (fractal_number);
}

int	mlx_data_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->window_ptr = mlx_new_window(data->mlx_ptr, WIDTH,
			HEIGHT, "Fractololol");
	if (data->window_ptr == NULL)
		return (0);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (data->img_ptr == NULL)
		return (0);
	data->addr_ptr = mlx_get_data_addr(data->img_ptr,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	if (data->addr_ptr == NULL)
		return (0);
	return (1);
}

int	data_init(t_data *data, int argc, char **argv)
{
	if (mlx_data_init(data) == 0)
		return (0);
	data->fractal = fractal_type(argv[1]);
	data->zoom = 1.0;
	data->x_offset = 0;
	data->y_offset = 0;
	data->x_pixel = 0.0;
	data->y_pixel = 0.0;
	data->x_re = 0.0;
	data->y_im = 0.0;
	if (argc == 4 && ft_is_number(argv[2]) && ft_is_number(argv[3]))
	{
		data->julia_x = ft_atod(argv[2]);
		data->julia_y = ft_atod(argv[3]);
	}
	else
	{
		data->julia_x = -0.7;
		data->julia_y = -0.3;
	}
	data->color_shift = 0;
	data->back_color = 0x0000FF;
	data->front_color = 0xFFFFFF;
	return (1);
}
