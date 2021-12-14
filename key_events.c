/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:43:29 by dleaves           #+#    #+#             */
/*   Updated: 2021/12/14 22:43:31 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == UP)
		data->y_offset -= MOVE_OFFSET;
	if (keycode == DOWN)
		data->y_offset += MOVE_OFFSET;
	if (keycode == LEFT)
		data->x_offset -= MOVE_OFFSET;
	if (keycode == RIGHT)
		data->x_offset += MOVE_OFFSET;
	if (keycode == ONE || keycode == TWO || keycode == THREE)
		change_color(keycode, data);
	mlx_clear_window(data->mlx_ptr, data->window_ptr);
	fractal_drawing(data);
	return (0);
}

int	ft_close(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
		free(data);
		exit(0);
	}
	else
		return (0);
}
