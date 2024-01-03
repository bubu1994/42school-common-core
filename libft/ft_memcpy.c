/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:46:32 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/11/03 10:46:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*copy;

	if (dest == NULL && src == NULL)
		return (NULL);
	copy = (char *) dest;
	while (n)
	{
		*copy++ = *(char *) src++;
		n--;
	}
	return (dest);
}
/*
#include <strings.h>

int	main(void)
{
	char s[] = "123456789";
	char a[20];
	printf("%s\n", memcpy(a, s, 4));

	char s2[] = "abcdefgh";
	char a2[21];
	printf("%s\n", ft_memcpy(a2, s2 + 2, 5));
	return (0);
}*/
