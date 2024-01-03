/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:09:19 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/10/26 09:54:46 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < (n - 1))
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
/*
int	main()
{
	char s[] = "\0";
	char s2[] = "\1";
	printf("%d\n", strncmp(s, s2, 7));
	printf("%d\n", ft_strncmp(s, s2, 7));
	char t[] = "\200";
	char t2[] = "\0";
	printf("%d\n", strncmp(t, t2, 7));
	printf("%d\n", ft_strncmp(t, t2, 7));
	return (0);
}*/
