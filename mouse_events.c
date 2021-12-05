/*#include "fractol.h"

int	mouse_button_hook(int button, int x, int y, t_vars *vars)
{
	if (x >= 0 && y >= 0)
	{
		if (button == SCROLL_UP)
			vars->zoom *= 1.2;
		else if (button == SCROLL_DOWN)
			vars->zoom /= 1.2;
		if (vars->type == 1)
			mandelbrot_set(vars);
		else if (vars->type == 2)
			julia_set(vars);
	}
	return (0);
}

int	mouse_move_hook(t_vars *vars)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(vars->mlx, vars->win, &x, &y);
	vars->cr = (double)x / (double)W_WIDTH * (R_END_J - R_START_J);
	vars->ci = (double)y / (double)W_HEIGHT * (I_END_J - I_START_J);
	julia_set(vars);
	return (0);
}

void				set_up_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, (1L << 0), key_hook, mlx);
	mlx_hook(mlx->win, 4, (1L << 2), mouse_click_hook, mlx);
	mlx_hook(mlx->win, 6, (1L << 13), mouse_move_hook, mlx);
    //mlx_hook(f->mlx.win, 6, 3, mouse_mover, f);
	mlx_hook(mlx->win, 17, 0L, on_close, mlx);
}

int	mouse_hooks(int key, int x, int y, t_data *data)
{
	if (f->mouse.move == 1)
		mouse_mover(x, y, f);
	if (key == MOUSE_UP_SCRLL)
		zoom_in(x, y, f);
	if (key == MOUSE_DOWN_SCRLL)
		zoom_out(x, y, f);
	return (0);
}*/