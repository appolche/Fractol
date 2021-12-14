/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:33:38 by dleaves           #+#    #+#             */
/*   Updated: 2021/12/14 22:35:13 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->addr_ptr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

void	color_filling(t_data *data, int iteration, int column, int row)
{
	if (iteration >= MAX_ITERATION)
		my_mlx_pixel_put(data, column, row, data->front_color);
	else
		my_mlx_pixel_put(data, column, row, data->back_color * iteration / 10);
}

void	change_color(int keycode, t_data *data)
{
	if (keycode == ONE)
	{
		data->color_shift = 1;
		data->front_color = 0xffefd5;
		data->back_color = 0x483d8b;
	}
	if (keycode == TWO)
	{
		data->color_shift = 2;
		data->front_color = 0xf0fff0;
		data->back_color = 0xffebcd;
	}
	if (keycode == THREE)
	{
		data->color_shift = 3;
		data->front_color = 0xe6e6fa;
		data->back_color = 0x8b4513;
	}
}
