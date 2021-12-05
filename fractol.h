#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <math.h>
#include "./mlx/mlx.h"
#include <stdlib.h>

# define WIDTH 		1024
# define HEIGHT		768

# define MAX_ITERATION	1000

# define ESC 53
/*# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define KEY_ENTER 36
# define MOUSE_LEFT_CLK		(0x01)
# define MOUSE_RIGHT_CLK	(0x02)
# define MOUSE_MIDDLE_CLK	(0x03)*/

# define MOUSE_UP_SCROLL		(0x04)
# define MOUSE_DOWN_SCROLL	(0x05)

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
	int		x_pos;
	int		y_pos;
}				t_data;

int	ft_strcmp(const char *dst, const char *src);
int mandelbrot(t_data *data, int column, int row);
void fractal_drawing(t_data *data);
void my_mlx_pixel_put(t_data *data, int x, int y, int colour);
int ft_close(int keycode, t_data *data);

//add show_manual();

#endif