/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:08:34 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:08:34 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**modif_heredoc(t_data *data, char **txt)
{
	int	i;
	int	j;

	i = 0;
	while (txt[i])
	{
		j = 0;
		while (txt[i][j])
		{
			if (txt[i][j] == '$' && txt[i][j + 1] != 0
				&& txt[i][j + 1] != ' ' && txt[i][j + 1] != '\n')
			{
				if (txt[i][j + 1] == '?')
					txt[i] = expand_exit_status_heredoc(data, txt[i]);
				else if (ft_isalnum(txt[i][j + 1]) == 1)
					txt[i] = expand_var_env_heredoc(data, txt[i]);
			}
			j++;
		}
		i++;
	}
	return (txt);
}

static char	**create_tab(int fd)
{
	char	**txt;
	int		i;
	int		bytes_read;
	char	buff[3000];

	bytes_read = 1;
	i = 0;
	txt = NULL;
	txt = malloc(500 * sizeof(char *));
	if (!txt)
		return (NULL);
	while (0 < bytes_read && i < 500)
	{
		bytes_read = read(fd, buff, 2999);
		buff[bytes_read] = '\0';
		txt[i] = ft_strdup(buff);
		i++;
	}
	txt[i] = NULL;
	return (txt);
}

void	expand_heredoc(t_data *data)
{
	char	**txt;
	int		a;
	int		fd;

	fd = open(".redir_main", O_RDWR);
	txt = create_tab(fd);
	close(fd);
	txt = modif_heredoc(data, txt);
	a = 0;
	fd = open(".redir_main", O_RDWR);
	while (txt[a] != NULL)
	{
		ft_putstr_fd(txt[a], fd);
		a++;
	}
	close(fd);
	free_tab(txt);
}
