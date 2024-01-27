/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:57:56 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/11/07 10:19:28 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	j;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len > SIZE_MAX || !s)
		return (0);
	subs = malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (0);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		subs[j++] = s[i++];
	subs[j] = '\0';
	return (subs);
}
/*
int	main(void)
{
	char *s = ft_substr("hola", 0, SIZE_MAX);
	printf("%s\n", s);
	printf("%zu\n", SIZE_MAX);
	printf("%llu\n", UINT64_MAX);
	free(s);
	return (0);
}*/
