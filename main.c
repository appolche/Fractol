#include "fractol.h"

/*static int init_fractal_parameters(char **argv)
{
    int parameter;

    parameter = 0;
	if (ft_strisdigit(argv[2]) && ft_strisdigit(argv[3]))
    {
		parameter = ft_atoi(argv[2]);
    }
	else
		return(parameter);
}*/

static int  fractal_name(char *str)
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
    data->fractal = fractal_name(argv);
    data->x_pos = WIDTH / 2;
	data->y_pos = HEIGHT / 2;
    return (1);
}

int	mouse_hooks(int keycode, int x, int y, t_data *data)
{
	if (keycode == MOUSE_UP_SCROLL)
    //if (keycode == 5 || keycode == 1)
		zoom_in(x, y, data);
	if (keycode == MOUSE_DOWN_SCROLL)
    //else if (keycode == 4 || keycode == 2)
		zoom_out(x, y, data);
	return (0);
}

int main(int argc, char **argv)
{
    t_data *data;

    if (argc == 2 && (fractal_name(argv[1]) != 0))
    {
        data = (t_data *)malloc(sizeof(t_data));
        if (data == NULL)
            return (0);
        if (!data_init(data, argv[1]))
        {
            free(data);
            return (0);
        }
        if (data->fractal == 1)
            fractal_drawing(data);
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->img_ptr, 0, 0);
        mlx_hook(data->window_ptr, 2, 1L << 0, ft_close, data);
        mlx_mouse_hook(data->window_ptr, mouse_hooks, data);
        //mlx_key_hook(matrix_map->win_ptr, get_event, matrix_map);
        mlx_loop(data->mlx_ptr);
    }
    else
        return (0);
}