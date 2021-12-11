#include "fractol.h"

static int  fractal_type(char *str)
{
    int fractal_number;

    fractal_number = 0;
	if (ft_strcmp(str, "mandelbrot") == 0)
		fractal_number = 1;
	else if (ft_strcmp(str, "julia") == 0)
		fractal_number = 2;
	return (fractal_number);
}

int data_init(t_data *data, char *argv)
{
    data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
        return (0);
    data->window_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fractololol");
    if (data->window_ptr == NULL)
        return (0);
    data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    if (data->img_ptr == NULL)
        return (0);
    data->addr_ptr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length, &data->endian);
    if (data->addr_ptr == NULL)
        return (0);
    data->fractal = fractal_type(argv);
    data->zoom = 1.0;
    data->x_offset = 0;
    data->y_offset = 0;
    return (1);
}

int main(int argc, char **argv)
{
    t_data *data;

    if (argc == 2 && (fractal_type(argv[1]) != 0))
    {
        data = (t_data *)malloc(sizeof(t_data));
        if (data == NULL)
            return (0);
        if (data_init(data, argv[1]) == 0)
        {
            free(data);
            return (0);
        }
        fractal_drawing(data);
        mlx_hook(data->window_ptr, 2, 1L << 0, key_pressed, data);
        mlx_mouse_hook(data->window_ptr, mouse_hooks, data);
        mlx_hook(data->window_ptr, 2, 1L << 0, ft_close, data);
        //mlx_key_hook(matrix_map->win_ptr, get_event, matrix_map);
        mlx_loop(data->mlx_ptr);
    }
    else
        return (0);
}