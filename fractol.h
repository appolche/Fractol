#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <math.h>
#include "./mlx/mlx.h"
#include <stdlib.h>

# define WIDTH 		1024
# define HEIGHT		768

# define MAX_ITERATION	100

//добавить в make флаг -Ofast

typedef struct	s_data {
    void	*mlx_ptr;
	void	*window_ptr;
	void	*img_ptr;
	char	*addr_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fractal;
}				t_data;

int	ft_strcmp(const char *dst, const char *src);
void draw_mandelbrot (t_data *data);
void my_mlx_pixel_put(t_data *data, int x, int y, int colour);
int ft_close(int keycode, t_data *data);

#endif