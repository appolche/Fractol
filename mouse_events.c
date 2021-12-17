/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:44:31 by dleaves           #+#    #+#             */
/*   Updated: 2021/12/14 22:45:06 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hooks(int keycode, int x, int y, t_data *data)
{
	if (keycode == MOUSE_UP_SCROLL)
		data->zoom *= ZOOM_OFFSET;
	else if (keycode == MOUSE_DOWN_SCROLL)
		data->zoom /= ZOOM_OFFSET;
	else if (keycode == MOUSE_CLICK_L)
	{
		data->zoom *= ZOOM_OFFSET;
		mlx_mouse_get_pos(data->window_ptr, &x, &y);
		data->x_pixel = (x - WIDTH / 2.0) * 4 / WIDTH;
		data->y_pixel = (y - HEIGHT / 2.0) * 4 / WIDTH;
	}
	else if (keycode == MOUSE_CLICK_R)
	{
		data->zoom /= ZOOM_OFFSET;
		mlx_mouse_get_pos(data->window_ptr, &x, &y);
		data->x_pixel = (x - WIDTH / 2.0) * 4 / WIDTH;
		data->y_pixel = (y - HEIGHT / 2.0) * 4 / WIDTH;
	}
	mlx_clear_window(data->mlx_ptr, data->window_ptr);
	fractal_drawing(data);
	return (0);
}
