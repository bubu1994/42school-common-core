/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:23:24 by sforster          #+#    #+#             */
/*   Updated: 2024/09/26 16:34:00 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unlink_heredoc(void)
{
	char		oldpwd[PATH_MAX];

	getcwd(oldpwd, sizeof(oldpwd));
	chdir("obj/redirections");
	unlink(".redir_main");
	chdir(oldpwd);
	return ;
}
