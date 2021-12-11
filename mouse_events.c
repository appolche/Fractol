#include "fractol.h"

int mouse_hooks(int keycode, int x, int y, t_data *data)
{
	if (keycode == MOUSE_UP_SCROLL || keycode == MOUSE_CLICK_L)
		data->zoom *= ZOOM_OFFSET;
	else if (keycode == MOUSE_DOWN_SCROLL || keycode == MOUSE_CLICK_R)
		data->zoom /= ZOOM_OFFSET;
	//mlx_clear_window(data->mlx_ptr, data->window_ptr);
	//mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	fractal_drawing(data);
	return (0);
}
