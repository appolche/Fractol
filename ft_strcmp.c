#include "fractol.h"

int	ft_strcmp(const char *dst, const char *src)
{	
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/*
double imabs = sqrt(x * x + y * y);
 my_mlx_pixel_put(stuff, column, row, 0x00FF0000/imabs * 100);*/