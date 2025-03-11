/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:54:57 by marvin            #+#    #+#             */
/*   Updated: 2024/07/22 10:54:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*new_elem(char *env)
{
	t_env	*res;
	char	**split_env;

	res = malloc(sizeof(t_env));
	if (!res)
		return (NULL);
	split_env = ft_split(env, '=');
	res->env = ft_strdup(split_env[0]);
	if (split_env[1])
		res->cont = ft_strdup(split_env[1]);
	else
	{
		res->cont = ft_strdup("(null)");
	}
	res->next = NULL;
	free_tab(split_env);
	return (res);
}

static void	add_back(t_env **lst, t_env *new)
{
	t_env	*back;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	back = *lst;
	while (back->next)
		back = back->next;
	back->next = new;
}

t_env	*env_list(char **env)
{
	t_env	*res;
	t_env	*new;
	int		i;

	if (!env)
		return (NULL);
	i = 0;
	res = NULL;
	while (env[i])
	{
		new = new_elem(env[i]);
		add_back(&res, new);
		i++;
	}
	return (res);
}
