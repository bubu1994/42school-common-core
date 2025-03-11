/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_open_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:23:13 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/09/29 19:23:13 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
void	list_open_fds(void)
{
	struct dirent	*entry;
	DIR				*dir;

	dir = opendir("/proc/self/fd");
	if (dir == NULL)
	{
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	printf("Open file descriptors:\n");
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] != '.')
		{
			printf("FD: %s\n", entry->d_name);
		}
	}
	closedir(dir);
}*/