/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:59:33 by gebuqaj           #+#    #+#             */
/*   Updated: 2023/10/31 16:41:18 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	sizetab(const char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			n++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (n);
}

static char	*substr(char const *s, char c)
{
	int		i;
	char	*str;
	int		size;

	i = 0;
	size = 0;
	while (s[size] != '\0' && s[size] != c)
		size++;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0' && i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (sizetab(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			tab[j] = substr(s + i, c);
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	tab[j] = 0;
	return (tab);
}
/*
int	main(int argc, char **argv)
{
	(void) argc;
	int i = 0;
	char **tab = ft_split(argv[1], argv[2][0]);
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free(tab);
	return (0);
}*/
