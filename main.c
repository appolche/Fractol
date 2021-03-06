/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:43:53 by dleaves           #+#    #+#             */
/*   Updated: 2021/12/14 22:44:19 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_moving_tips(void)
{
	printf("\nMOVE: up || down || left || right\n");
	printf("\nZOOM: mouse wheel || mouse click (left || right)\n");
	printf("\nCHANGE COLOR : 1 || 2 || 3\n");
	printf("\nEXIT: esc\n");
}

void	print_parameters_list(void)
{
	printf("\nPlease add a fractal name:\n");
	printf("\n1: MANDELBROT\n");
	printf("\n2: JULIA\n");
	printf("\n3: SERPINSKIY\n\n");
}

int	main(int argc, char **argv)
{
	t_data	*data;

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
