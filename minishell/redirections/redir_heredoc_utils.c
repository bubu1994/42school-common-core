/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:19:44 by sforster          #+#    #+#             */
/*   Updated: 2024/09/26 19:01:08 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlcpy2(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < srcsize && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

int	ft_var_len(char *txt)
{
	int	i;

	i = 0;
	while (txt[i + 1])
	{
		if (txt[i] == '$' && ft_isalnum(txt[i + 1]) == 1)
			break ;
		i++;
	}
	return (i);
}

char	*tmp_joined(char *new_txt, char *txt, char *tmp, int i)
{
	tmp = ft_strjoin(new_txt, txt + i);
	double_free(new_txt, txt);
	return (tmp);
}
