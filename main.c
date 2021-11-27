#include "fractol.h"


void my_mlx_pixel_put(t_data *stuff, int x, int y, int xor)
{
    char *dst;

    dst = stuff->addr_ptr + (y * stuff->line_length + x * (stuff->bits_per_pixel / 8));
    *(unsigned int *)dst = xor;
}

int ft_close(int keycode, t_data *stuff)
{
    mlx_destroy_window(stuff->mlx_ptr, stuff->window_ptr);
    exit(0);
}
void stuff_init(t_data *stuff)
{
    stuff->mlx_ptr = NULL;
    stuff->window_ptr = NULL;
    stuff->img_ptr = NULL;
    stuff->addr_ptr = NULL;
    stuff->bits_per_pixel = 0;
    stuff->line_length = 0;
    stuff->endian = 0;
    stuff->fractal = 0;
}

int main(int argc, char **argv)
{
    t_data *stuff;
    int x = 0;
    int y = 0;
    int max = 100;
    int iteration = 0;

    if (argc == 2)
    {
        stuff = (t_data *)malloc(sizeof(t_data));
        if (stuff == NULL)
            return (0);
        //stuff->fractal = arguments_handler(argv[1]);
        stuff->mlx_ptr = mlx_init();
        stuff->window_ptr = mlx_new_window(stuff->mlx_ptr, WIDTH, HEIGHT, "Hello world!");
        stuff->img_ptr = mlx_new_image(stuff->mlx_ptr, WIDTH, HEIGHT);
        stuff->addr_ptr = mlx_get_data_addr(stuff->img_ptr, &stuff->bits_per_pixel, &stuff->line_length, &stuff->endian);

        while (y < HEIGHT)
        {
            x = 0;
            while (x < WIDTH)
            {
                double c_re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
                double c_im = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
                double x = 0, y = 0;
                iteration = 0;
                while (x * x + y * y <= 4 && iteration < max)
                {
                    double x_new = x * x - y * y + c_re;
                    y = 2 * x * y + c_im;
                    x = x_new;
                    iteration++;
                }
                x++;
            }
            if (iteration < max)
                my_mlx_pixel_put(stuff, x, y, 0x00FF0000);
            else
                my_mlx_pixel_put(stuff, x, y, 0x00B0E000);
            y++;
        }

        mlx_put_image_to_window(stuff->mlx_ptr, stuff->window_ptr, stuff->img_ptr, 0, 0);
        mlx_hook(stuff->window_ptr, 2, 1L << 0, ft_close, stuff);
        mlx_loop(stuff->mlx_ptr);
    }
    else
        return (0);
}