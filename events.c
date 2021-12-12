#include "fractol.h"

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == UP)
		data->y_offset -= MOVE_OFFSET;
	else if (keycode == DOWN)
		data->y_offset += MOVE_OFFSET;
	else if (keycode == LEFT)
		data->x_offset -= MOVE_OFFSET;
	else if (keycode == RIGHT)
		data->x_offset += MOVE_OFFSET;
	mlx_clear_window(data->mlx_ptr, data->window_ptr);
	//mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	fractal_drawing(data);
	return (0);
}

int ft_close(int keycode, t_data *data)
{
    if (keycode == ESC)
    {
        mlx_destroy_image(data->mlx_ptr, data->img_ptr);
        //mlx_clear_window(matrix_map->mlx_ptr, matrix_map->win_ptr);
        mlx_destroy_window(data->mlx_ptr, data->window_ptr);
        // mlx_destroy_display(data->mlx_ptr);    https://aurelienbrabant.fr/blog/events-with-the-minilibx
        free(data);
        exit(0);
    }
    else 
        return (0);
}
