/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:15:35 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/11/06 14:57:10 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	int		i;

	str = b;
	i = 0;
	while (len > 0)
	{
		str[i] = (unsigned char) c;
		len--;
		i++;
	}
	return (b);
}
/*
int	main(void)
{
	char b[5];
	printf("%s\n", ft_memset(b, 'a', sizeof(char) * 5));
	return (0);
}*/
