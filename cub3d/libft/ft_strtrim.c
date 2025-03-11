/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:58:59 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/10/31 16:42:38 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_is_in(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*s;

	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	while (c_is_in(s1[start], set) && s1[i] != '\0')
		start++;
	while (c_is_in(s1[end], set) && end != 0)
		end--;
	if (end - start < 0)
		s = malloc(1);
	else
		s = malloc(sizeof(char) * (end - start + 2));
	if (!s)
		return (NULL);
	while (i <= end - start)
	{
		s[i] = s1[start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
/*
int main(void)
{
    char s[] = "Bonjour";
    char tr[] = "Bonjour";
    char *trimmed = ft_strtrim(s, tr);
    if (trimmed)
    {
        printf("%s\n", trimmed);
        free(trimmed);
    }
    return 0;
}
*/