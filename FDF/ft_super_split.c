/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_super_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:25:07 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/29 14:26:20 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static int	check_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static int	sizetab(char *str, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		while (!check_char(str[i], charset) && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			size++;
		while (check_char(str[i], charset) && str[i] != '\0')
			i++;
	}
	return (size);
}

static char	*substr(char *str, char *charset)
{
	int		i;
	int		len;
	char	*subs;

	i = 0;
	len = 0;
	while (str[len] != '\0' && check_char(str[len], charset))
		len++;
	subs = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		subs[i] = str[i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	**ft_super_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (sizetab(str, charset) + 1));
	if (!tab)
		return (NULL);
	while (str[i] != '\0')
	{
		while (!check_char(str[i], charset) && str[i] != '\0')
			i++;
		if (str[i] != '\0')
		{
			tab[j] = substr(str + i, charset);
			j++;
		}
		while (check_char(str[i], charset) && str[i] != '\0')
			i++;
	}
	tab[j] = 0;
	return (tab);
}