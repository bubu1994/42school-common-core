/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:32:40 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/11/06 18:21:40 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char) c)
			return ((char *) s + i);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) s + i);
	return (0);
}
/*
int	main(void)
{
	char s[] = "bonjour";
    int c = '\0';
	printf("%s\n", strchr(s, c));
	printf("%s\n", ft_strchr(s, c));
    return 0;
}*/
