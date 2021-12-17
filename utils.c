/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleaves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:45:18 by dleaves           #+#    #+#             */
/*   Updated: 2021/12/14 23:08:10 by dleaves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_is_number(char *str)
{
	int	i;
	int	dot;

	if (!str)
		return (1);
	i = 0;
	dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.' && dot < 1)
				dot++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_find_sign(char *str, int sign)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
	}
	return (sign);
}

double	ft_atod(char *str)
{
	double	result;
	int		sign;
	int		n;

	result = 0;
	sign = 1;
	n = 10;
	while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n'
		|| *str == '\v' || *str == '\f')
		str++;
	sign = ft_find_sign(str, sign);
	if (sign == -1)
		str++;
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
