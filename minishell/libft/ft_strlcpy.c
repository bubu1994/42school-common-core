/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:10:09 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/11/06 16:40:52 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;

	n = ft_strlen((char *) src);
	if (dstsize > n + 1)
		ft_memcpy(dst, src, n + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (n);
}
/*
int	main()
{
	char de[] = "vi";
	char s[] = "hola senor";
	printf("%zu\n", ft_strlcpy(de, s, 30));
	return (0);
}*/
