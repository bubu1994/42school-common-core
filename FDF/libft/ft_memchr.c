/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:56:21 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/10/26 11:49:04 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	b;

	i = 0;
	p = (unsigned char *) s;
	b = (unsigned char) c;
	while (i < n)
	{
		if (p[i] == b)
			return ((void *) p + i);
		i++;
	}
	return (0);
}
/*
int	main()
{
	char s[] = "bonjour";
	int c = 'b';
	printf("%d\n", c);
	printf("%p\n", &s);
	printf("%p\n", memchr(s, c, 10));
	printf("%p\n", ft_memchr(s, c, 10));
	return (0);
}*/
