/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:36:02 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/01/25 13:32:32 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*trim_untilnewline(char *str)
{
	int		i;
	int		k;
	char	*res;

	i = 0;
	k = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	res = ft_calloc((ft_strlen(str) - i), sizeof(char));
	i++;
	while (str[i] != '\0')
		res[k++] = str[i++];
	free(str);
	return (res);
}

char	*trim_afternewline(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	res = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i] = '\n';
	return (res);
}

char	*read_str(int fd, char *str)
{
	char	*buf;
	int		chars_read;

	if (!str)
		str = ft_calloc(1, 1);
	buf = ft_calloc(1, 1);
	chars_read = 43;
	while (!ft_strchr(str, '\n'))
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free(buf);
			return (NULL);
		}
		if (chars_read == 0)
			break ;
		buf[chars_read] = '\0';
		str = ft_strjoin_gnl(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = read_str(fd, str);
	if (str == NULL)
		return (NULL);
	line = trim_afternewline(str);
	str = trim_untilnewline(str);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	int		count;
	char	*next_line;
	char	*path;

	count = 1;
	path = "1charfile.txt";
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while (count < 10)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		printf("%d: %s", count, next_line);
		count++;
		free(next_line);
	}
	close(fd);
	return (0);
}
*/