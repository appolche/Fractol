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
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define SPACE 124
/*# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define KEY_ENTER 36
# define MOUSE_LEFT_CLK		(0x01)
# define MOUSE_RIGHT_CLK	(0x02)
# define MOUSE_MIDDLE_CLK	(0x03)*/

# define MOUSE_UP_SCROLL	4
# define MOUSE_DOWN_SCROLL	5
# define MOUSE_CLICK_L 1
# define MOUSE_CLICK_R 2


# define MOVE_OFFSET 10
# define ZOOM_OFFSET 1.25

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
	double			x_mouse_pos;
	double			y_mouse_pos;
	double			x;
	double			y;
	double			zoom;
	int			x_offset;
	int			y_offset;
}				t_data;

static int fractal_type(char *str);
int	ft_strcmp(const char *dst, const char *src);
int data_init(t_data *data, char *argv);
void fractal_drawing(t_data *data);
int mandelbrot(t_data *data, int column, int row);
//add Julia_func
void color_filling(t_data *data, int iteration, int column, int row);
void my_mlx_pixel_put(t_data *data, int x, int y, int colour);
int ft_close(int keycode, t_data *data);
int mouse_hooks(int keycode, int x, int y, t_data *data);
int	key_pressed(int keycode, t_data *data);
void next_draw(t_data *data);
//add free_func


//add show_manual();

#endif