/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:56:59 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/09/22 09:28:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_calloc(1, 1);
	str = malloc((ft_strlen((char *) s1) + ft_strlen((char *) s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*trim_until_newline(char *str)
{
	char	*res;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	res = ft_calloc(ft_strlen(str) - i, sizeof(char));
	i++;
	while (str[i] != '\0')
		res[k++] = str[i++];
	free(str);
	return (res);
}

char	*trim_after_newline(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	res = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i] = '\0';
	return (res);
}

char	*read_file_and_reset_str(int fd, char *str)
{
	char	*buf;
	int		n;

	if (!str)
		str = ft_calloc(1, 1);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = 42;
	while (!ft_strchr(str, '\n'))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free(buf);
			return (NULL);
		}
		if (n == 0)
			break ;
		buf[n] = '\0';
		str = ft_strjoin_gnl(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = read_file_and_reset_str(fd, str);
	if (str == NULL)
		return (NULL);
	line = trim_after_newline(str);
	str = trim_until_newline(str);
	return (line);
}
/*
int	main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *line;
	int i = 1;

	while (i < 15)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%d) %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}*/