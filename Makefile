NAME		=	fractol
MLX			=	libmlx.a

MLX_DIR	=	mlx

HEADER		=	fractol.h
MLX_HEADER  =   $(addprefix $(MLX_DIR)/, mlx_int.h mlx_new_window.h mlx_opengl.h mlx_png.h mlx.h)

SRCS		= 	main.c\
				utils.c \
				fractal.c\
				color.c\
				key_events.c\
				mouse_events.c\

OBJS		=	$(SRCS:.c=.o)

MLX_FLAGS	=	-I $(MLX_DIR)/ -framework OpenGL -framework AppKit
FLAGS		=	-Wall -Wextra -Werror -g -Ofast
CC			=	gcc
GCC			=	$(CC) $(FLAGS)


all:			$(NAME)

%.o:			%.c $(HEADER) $(MLX_HEADER)
				$(GCC) -c -o $@ $<
 
$(NAME):		$(OBJS)
				cd $(MLX_DIR) && $(MAKE)
				$(GCC) $(MLX_FLAGS) $(MLX_DIR)/$(MLX) $(OBJS) -o $(NAME)

clean:				
				rm -f $(OBJS)
				cd $(MLX_DIR) && $(MAKE) clean

fclean:			clean
				rm -f $(NAME)
				cd $(MLX_DIR) && $(MAKE) clean

re:				fclean $(NAME)

.PHONY:			all clean fclean re
