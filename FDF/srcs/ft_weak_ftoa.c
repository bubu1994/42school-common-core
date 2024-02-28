/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weak_ftoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:48:58 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/02/24 12:32:30 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_strlen_s(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	str_size(long n)
{
	size_t		size;
	long		nb;

	size = 1;
	nb = n;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static char	*ft_ltoa(long n)
{
	char		*str;
	size_t		size;
	long		nb;

	nb = n;
	size = str_size(n);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (nb < 0)
		nb *= -1;
	while (size--)
	{
		str[size] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (str[0] == '0' && str[1] != '\0')
		str[0] = '-';
	return (str);
}

static void	norminette_for_ever(int i, char *res, char *str, int size)
{
	while (i < size - 6)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '.';
	i++;
	while (i <= size)
	{
		res[i] = str[i - 1];
		i++;
	}
	free(str);
	res[i] = '\0';
}

char	*ft_weak_ftoa(float value)
{
	char	*res;
	char	*str;
	int		size;
	int		i;

	if (value < 0.1 && value > -0.1)
		return (ft_strdup("0.000000"));
	i = 0;
	str = ft_ltoa(value * 1000000);
	size = ft_strlen_s(str);
	res = malloc(sizeof(char) * size + 2);
	if (!res)
		return (NULL);
	norminette_for_ever(i, res, str, size);
	return (res);
}
/*
//Doesn't work for -0.1 > n < 0.1
//Use snprintf if you are allowed

#include <stdio.h>

int main(int argc, char **argv)
{
	float n = -0.0701;
	char *s = ft_weak_ftoa(n);
	printf("%s\n", s);
	free(s);
}
*/