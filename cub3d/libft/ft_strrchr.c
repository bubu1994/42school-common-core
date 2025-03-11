/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaumann <sbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:50:46 by gebuqaj           #+#    #+#             */
/*   Updated: 2025/03/05 13:37:18 by sbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}
/*
int	main()
{
	char s[] = "macarena";
	int n = 'c' + 256;
	printf("%s\n", strrchr(s, n));
	printf("%s\n", ft_strrchr(s, n));
	return (0);
}*/
