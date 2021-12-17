/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:39:38 by dleaves           #+#    #+#             */
/*   Updated: 2021/12/16 22:21:28 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "./mlx/mlx.h"

# define WIDTH 1024
# define HEIGHT 768

# define MAX_ITERATION 1000

# define MOVE_OFFSET 10
# define ZOOM_OFFSET 1.111

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define ONE 18
# define TWO 19
# define THREE 20

# define MOUSE_UP_SCROLL 4
# define MOUSE_DOWN_SCROLL 5
# define MOUSE_CLICK_L 1
# define MOUSE_CLICK_R 2

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*img_ptr;
	char	*addr_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fractal;
	double	x_re;
	double	y_im;
	double	x_pixel;
	double	y_pixel;
	double	zoom;
	int		x_offset;
	int		y_offset;
	double	julia_x;
	double	julia_y;
	int		color_shift;
	int		back_color;
	int		front_color;
}	t_data;

int		data_init(t_data *data, int argc, char **argv);
int		mlx_data_init(t_data *data);

void	fractal_drawing(t_data *data);

int		mandelbrot(t_data *data, int row, int column);
int		julia(t_data *data, int row, int column);
int		serpinskiy(t_data *data, int row, int column);

void	change_color(int keycode, t_data *data);
void	color_filling(t_data *data, int iteration, int column, int row);
void	my_mlx_pixel_put(t_data *data, int x, int y, int colour);

int		ft_close(int keycode, t_data *data);
int		mouse_hooks(int keycode, int x, int y, t_data *data);
int		key_pressed(int keycode, t_data *data);
int		keys(int keycode, t_data *data);

int		fractal_type(char *str);
void	print_parameters_list(void);
void	print_moving_tips(void);

double	ft_atod(char *str);
int		ft_find_sign(char *str, int sign);
int		ft_is_number(char *str);
int		ft_isdigit(int c);
int		ft_strcmp(const char *dst, const char *src);

#endif
