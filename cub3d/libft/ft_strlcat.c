/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:29:04 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/11/06 16:25:37 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	while (src[j] && i + j < (dstsize - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}
/*
#include <string.h>
int	main()
{
	char s1[40] = "hola ";
	char s2[] = "senor gent";
	size_t n = 7;
	printf("%zu\n", strlcat(s1, s2, n));
	char c1[40] = "hola ";
	char c2[] = "senor gent";
	printf("%zu\n", ft_strlcat(c1, c2, 7));
	return (0);
}*/
