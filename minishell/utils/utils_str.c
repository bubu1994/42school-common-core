/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:09:41 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:09:41 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_char(char *s1, char const s2)
{
	int		i;
	char	*str;
	int		a;

	i = 0;
	a = 0;
	if (s1 != NULL)
		a = ft_strlen((char *)s1);
	str = malloc(sizeof(char) * (a + 2));
	if (!str)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
	}
	str[i] = s2;
	i++;
	str[i] = '\0';
	free (s1);
	return (str);
}

void	print_message(void)
{
	ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
}
