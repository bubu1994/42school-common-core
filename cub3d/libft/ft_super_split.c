/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_super_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaumann <sbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:02:17 by gebuqaj           #+#    #+#             */
/*   Updated: 2025/03/05 13:36:51 by sbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	s_sizetab(char *str, char *charset)
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

static char	*s_substr(char *str, char *charset)
{
	int		i;
	int		len;
	char	*subs;

	i = 0;
	len = 0;
	while (str[len] != '\0' && check_char(str[len], charset))
		len++;
	subs = malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	while (i < len)
	{
		subs[i] = str[i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

void	free_tableau(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_super_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (s_sizetab(str, charset) + 1));
	if (!tab)
		return (NULL);
	while (str[i] != '\0')
	{
		while (!check_char(str[i], charset) && str[i] != '\0')
			i++;
		if (str[i] != '\0')
		{
			tab[j] = s_substr(str + i, charset);
			if (!tab[j])
				free_tableau(tab);
			j++;
		}
		while (check_char(str[i], charset) && str[i] != '\0')
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
