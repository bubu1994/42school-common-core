/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:32:40 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/12/20 13:24:08 by gebuqaj          ###   ########.fr       */
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
