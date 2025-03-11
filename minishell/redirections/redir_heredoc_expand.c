/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc_expand.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:33:19 by sforster          #+#    #+#             */
/*   Updated: 2024/09/29 18:33:19 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_exit_status_heredoc(t_data *data, char *txt)
{
	char	*new_txt;
	char	*new_txt2;
	char	*tmp;
	int		i;

	i = 0;
	while (txt[i + 1] != '\0')
	{
		if (txt[i] == '$' && txt[i + 1] == '?')
			break ;
		i++;
	}
	i++;
	new_txt = malloc((i + 2) * sizeof(char));
	if (!new_txt)
		return (NULL);
	ft_strlcpy2(new_txt, txt, i);
	new_txt[i + 1] = '\0';
	i += 2;
	tmp = ft_itoa(data->exit_status);
	new_txt2 = ft_strjoin(new_txt, tmp);
	double_free(tmp, new_txt);
	new_txt = ft_strjoin(new_txt2, txt + i - 1);
	double_free(new_txt2, txt);
	return (new_txt);
}

char	*extract_env_name_heredoc(char *txt)
{
	int		i;
	char	*env_name;

	i = 0;
	while (txt[i] && ft_isalnum(txt[i]) == 1)
		i++;
	i++;
	env_name = malloc(i + 1 * sizeof(char));
	if (!env_name)
		return (NULL);
	ft_strlcpy2(env_name, txt, i);
	env_name[i] = '\0';
	return (env_name);
}

static char	*new_env_heredoc(t_env *env, char *txt)
{
	t_env	*scan;
	char	*new_env;

	scan = env;
	while (scan)
	{
		if (ft_strcmp(scan->env, txt) == 0)
		{
			new_env = ft_strdup(scan->cont);
			return (new_env);
		}
		scan = scan->next;
	}
	return (NULL);
}

char	*expand_var_env_heredoc(t_data *data, char *txt)
{
	char	*new_txt;
	char	*tmp;
	char	*tmp2;
	int		i;

	i = ft_var_len(txt);
	new_txt = malloc((i + 2) * sizeof(char));
	if (!new_txt)
		return (NULL);
	ft_strlcpy2(new_txt, txt, i + 1);
	new_txt[i] = '\0';
	i += 1;
	tmp = extract_env_name_heredoc(txt + i);
	i += ft_strlen(tmp);
	tmp2 = new_env_heredoc(data->env, tmp);
	free(tmp);
	if (tmp2 == NULL)
		return (tmp_joined(new_txt, txt, tmp, i));
	tmp = ft_strjoin(new_txt, tmp2);
	double_free(new_txt, tmp2);
	new_txt = ft_strjoin(tmp, txt + i);
	double_free(tmp, txt);
	return (new_txt);
}
