#include "fractol.h"

int ft_strcmp(const char *dst, const char *src)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int is_double_number(char *str)
{
	int i;
	int dot;

	if (!str)
		return (0);
	i = 0;
	dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		while (ft_isdigit(str[i]) && str[i])
			i++;
		if (str[i] == '.' && dot <= 1)
		{
			dot++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

double ft_atod(const char *str)
{
	double result;
	int sign;
	int n;

	n = 10;
	while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			result += (double)(*str++ - '0') / n;
			n *= 10;
		}
	}
	return (sign * result);
}