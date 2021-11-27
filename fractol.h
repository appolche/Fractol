#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <math.h>
#include "./mlx/mlx.h"
#include <stdlib.h>

# define WIDTH 		620
# define HEIGHT		480

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

/*
typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fractal;
	int			color;
	int			width;
	int			height;
}				t_data;
*/

int	ft_strcmp(const char *dst, const char *src);

#endif