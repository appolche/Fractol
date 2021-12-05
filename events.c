#include "fractol.h"

int ft_close(int keycode, t_data *data)
{
    if (keycode == ESC)
    {
        mlx_destroy_image(data->mlx_ptr, data->img_ptr);
        // mlx_clear_window(matrix_map->mlx_ptr, matrix_map->win_ptr);
        mlx_destroy_window(data->mlx_ptr, data->window_ptr);
        // mlx_destroy_display(data->mlx_ptr);    https://aurelienbrabant.fr/blog/events-with-the-minilibx
        free(data);
        exit(0);
    }
    else 
        return (0);
}
