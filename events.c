#include "fractol.h"

int ft_close(int keycode, t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img_ptr);
    mlx_destroy_window(data->mlx_ptr, data->window_ptr);
    //mlx_destroy_display(data->mlx_ptr);    https://aurelienbrabant.fr/blog/events-with-the-minilibx
    exit(0);
}

