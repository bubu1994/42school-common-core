/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:13:21 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/11/08 14:40:21 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_size(int n)
{
	size_t		size;
	long int	nb;

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

char	*ft_itoa(int n)
{
	char		*str;
	size_t		size;
	long int	nb;

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
/*
int	main(void)
{
	int nb = 0006500;
	printf("%s\n", ft_itoa(nb));
	return (0);
}*/
