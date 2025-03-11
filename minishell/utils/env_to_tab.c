/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:08:56 by sforster          #+#    #+#             */
/*   Updated: 2024/09/25 11:08:56 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_tab_len(t_env *env)
{
	int		i;
	t_env	*scan;

	scan = env;
	i = 0;
	while (scan)
	{
		if (scan == NULL)
			break ;
		scan = scan->next;
		i++;
	}
	return (i);
}

char	**env_to_tab(t_env *env)
{
	char	**tab;
	int		i;
	t_env	*scan;
	char	*tmp;

	if (env == NULL)
		return (NULL);
	i = ft_tab_len(env);
	tab = malloc((i + 1) * sizeof(char *));
	if (!tab)
		return (0);
	scan = env;
	i = 0;
	while (scan)
	{
		if (scan == NULL)
			break ;
		tmp = ft_strjoin(scan->env, "=");
		tab[i] = ft_strjoin(tmp, scan->cont);
		free (tmp);
		scan = scan->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
