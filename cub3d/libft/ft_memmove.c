/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:37:16 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/11/06 18:27:23 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}
/*
#include <string.h>
int	main()
{
	char s[] = "Salut";
	printf("%s\n", memmove(s + 2, s, 2));
	char s2[] = "Salut";
	printf("%s\n", ft_memmove(s2 + 2, s2, 2));
	return (0);
}*/
