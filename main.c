#include "fractol.h"

int fractal_type(char *str)
{
    int fractal_number;

    fractal_number = 0;
    if (ft_strcmp(str, "mandelbrot") == 0)
        fractal_number = 1;
    else if (ft_strcmp(str, "julia") == 0)
        fractal_number = 2;
    else if (ft_strcmp(str, "serpinskiy") == 0)
        fractal_number = 3;
    return (fractal_number);
}

void print_parameters_list(void)
{
    printf("\nPlease add a fractal name:\n");
    printf("1: mandelbrot\n");
    printf("2: julia\n");
    printf("3: serpinskiy\n");
}

void print_moving_tips(void)
{
    printf("MOVE: up || down || left || right\n");
    printf("ZOOM: mouse wheel || mouse click (left + && right -)\n");
    printf("CHANGE COLOR : 1 || 2 || 3\n");
    printf("EXIT: esc\n");
}

int data_init(t_data *data, int argc, char **argv)
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
    data->fractal = fractal_type(argv[1]);
    data->zoom = 1.0;
    data->x_offset = 0;
    data->y_offset = 0;
    data->x_pixel = 0.0;
    data->y_pixel = 0.0;
    if (argc == 4 && (!is_double_number(argv[2]) || !is_double_number(argv[3])))
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
    return (1);
}

int main(int argc, char **argv)
{
    t_data *data;

    if (argc >= 2 && (fractal_type(argv[1]) != 0))
    {
        data = (t_data *)malloc(sizeof(t_data));
        if (data == NULL)
            return (0);
        if (data_init(data, argc, argv) == 0)
        {
            free(data);
            return (0);
        }
        print_moving_tips();
        fractal_drawing(data);
        mlx_key_hook(data->window_ptr, key_pressed, data);
        mlx_mouse_hook(data->window_ptr, mouse_hooks, data);
        mlx_hook(data->window_ptr, 2, 1L << 0, ft_close, data);
        mlx_loop(data->mlx_ptr);
    }
    else
        print_parameters_list();
    return (0);
}
