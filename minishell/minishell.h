/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:17:27 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/06/05 10:20:29 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <dirent.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <signal.h>
# include <termios.h>

# define RED     "\001\033[1;31m\002"
# define ORANGE  "\001\033[0;33m\002"
# define GREEN   "\001\033[0;32m\002"
# define YELLOW  "\001\033[1;33m\002"
# define BLUE    "\001\033[0;34m\002"
# define MAGENTA "\001\033[0;35m\002"
# define CYAN    "\001\033[0;36m\002"
# define WHITE   "\001\033[0;37m\002"
# define RESET   "\001\033[0m\002"

typedef enum s_symb
{
	LIT = 0,
	SUP,
	SUP_SUP,
	INF,
	INF_INF,
	FICHIER,
	QUOTED,
	DELIMITER,
	QUOTED_DELIMITER,
}	t_symb;

typedef enum s_shell_status
{
	shell_main = 0,
	shell_main_sig,
	get_next_pipe,
	heredoc,
	heredoc_sig,
	shell_execution,
	shell_execution_sig,
}	t_shell_status;

typedef struct s_word
{
	char			*str;
	t_symb			symb;
	int				pos;
	struct s_word	*next;
	struct s_word	*prev;
}	t_word;

typedef struct s_cmd
{
	char			*phrase;
	t_word			*words;
	char			**simple_cmd;
	bool			is_builtin;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_tok
{
	char			value;
	char			*type;
	struct s_tok	*next;
	struct s_tok	*prev;
}	t_tok;

typedef struct s_env
{
	char			*env;
	char			*cont;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	char			*input;
	int				exit_status;
	t_tok			*tokens;
	t_env			*env;
	t_env			*tmp_env;
	char			**env_tab;
	t_cmd			*cmds;
	pid_t			child_pids[100];
	int				n_child;
	int				saved_stdin;
}	t_data;

extern int	g_ext_sig;

void	rl_replace_line(const char *text, int clear_undo);
void	list_open_fds(void);

//redir heredoc_expand.c
char	*expand_exit_status_heredoc(t_data *data, char *txt);
char	*expand_var_env_heredoc(t_data *data, char *txt);
void	expand_heredoc(t_data *data);

//redire herdoc_utils.c
size_t	ft_strlcpy2(char *dst, const char *src, size_t dstsize);
int		ft_var_len(char *txt);
char	*tmp_joined(char *new_txt, char *txt, char *tmp, int i);

//signals.c

void	ft_relauch(void);
void	handle_sig_main(int sig);
void	handle_sig_next_pipe(int sig);
void	sign_handler(int shell_stat);

// terminal.c
void	termios_main(void);

//init
t_env	*env_list(char **env);
t_data	*init_data1(char **env, int argc, char **argv);

//parser
int		parsing(t_data *data);
int		quoting(t_tok *tokens);
char	**make_words(t_tok *tokens, bool **word_is_quoted_arr);
char	**the_command(t_word *words);
t_tok	*tokenise(char *input);
int		syntax_ok(t_tok *token);
t_cmd	*build_cmds(t_tok *tokens);
t_word	*build_words(t_tok *token);

// parsing_utils.c
void	ctrl_d_next_pipe(char *input, char *next_input, t_data *data);
char	*read_next_input(char *input, t_data *data);

//expanser
void	expand(t_data *data);

// expand_exit.c
void	expand_exit_status(t_data *data, t_tok *prem_d);
void	delete_elem(t_tok **head, t_tok *elem);

//expand_var_env.c
void	expand_var_env(t_data *data, t_tok *prem_d, char s);
char	*ft_strjoin_char(char *s1, char s2);
char	*assign_type(char c); //sort d ou celle la??

//expand_var_env.c
void	insert_new_tok(t_tok *prem_d, t_tok *new_tok);
void	add_tok_to_list(t_tok **list, t_tok *new);
t_tok	*add_new_tok_var(t_tok **list, char n, char s);
t_tok	*new_env_tok(t_env *env, char *str, char s);

//double_dollar.c
t_tok	*new_pid_tokens(int n);
char	*extract_env_name(t_data *data, t_tok *prem_d);
void	insert_new_tok(t_tok *prem_d, t_tok *new_tok);

////////////////////////////////////////////////////////////////////////////////

/// BUILTINS ///

//main_builtins.c
bool	is_builtin(char **tab);
void	exec_builtin(t_cmd *cmd, char **tab, t_data *data);
void	exec_builtin_in_child(t_cmd *cmd, char **tab, t_data *data);

//exit.c
void	ft_exit(t_cmd *cmd, t_data *data);

//echo.c
void	ft_echo(char **input, t_data *data);

/// CD ///

// cd_main.c
void	ft_cd(char **input, t_data *data);
bool	ft_check_access_folder(char *path, t_data *data);

// cd.c
void	ft_cd_base(t_data *data);
void	ft_absolute_path(char *path, t_data *data);
void	ft_relative_path(char *path_folder, t_data *data);
void	ft_close_dir(t_data *data);
void	ft_previous_dir(t_data *data);
char	*get_pwd(t_data *data);
char	*get_home(t_data *data);
char	*path_back(char *path, char *new_path);
char	*no_path(char *path);

// cd_pwd.c
void	oldpwd_cd(t_data *data);
t_env	*init_oldpwd(char *actualpwd);
void	newpwd_cd(char *path, t_data *data);
/// PWD ///

// pwd.c
void	ft_pwd(char **input, t_data *data);

/// EXPORT ///

void	ft_export(char **input, t_data *data);

//export_list.c
void	ft_export_list(t_data *data);
void	order_var_env(t_env **new_list, t_env *env);
void	order_var_env_var_tmp(t_env **new_list, t_env *env);
void	print_export(t_env *list);

//export_add_variable.c 
void	ft_add_variable(char **input, t_data *data);
bool	check_variable(char *v, t_data *data);
void	ft_add_var_env(char *input, t_data *data);
t_env	*add_new_env(char *input);
void	ft_add_var_tmp(char *input, t_data *data);

// export_utils.c
t_env	*new_env(t_env	*env);
void	pushback_base(t_env **new_list, t_env *actual_node);
void	check_tmp(t_data *data, t_env *newv);
t_env	*new_node_exp(char *str);

// unset_heredoc.c
void	unlink_heredoc(void);

/// UNSET ///

// unset.c
void	ft_unset(char **input, t_data *data);
void	unset_el(t_env **list, char *name);
void	free_env(t_env *env);

/// ENV ///

//env.c
void	ft_env(char **input, t_data *data);

////////////////////////////////////////////////////////////////////////////////

/// EXECUTION ///

void	exe_command(t_cmd *cmd, char **input, t_data *data, int fd[4]);
int		is_extern(char **input, t_data *data);
void	fork_extern_command(char **input, t_data *data, int fd[4]);
void	exec_extern(char **input, int fd[4], t_data *data);
void	execution(t_cmd *list, t_data *data);
bool	redirections(t_cmd *cmd, t_data *data, int fd[4]);

//execution_utils.c
void	restore_and_kill(t_data *data, int fd[4]);
void	dup_close(int fd[4]);
void	restore_close(t_data *data, int fd[4]);

//utils
void	free_tab(char **tabl);
int		nb_of_elem(char **tabl);
void	error_exit(char *error_message);
void	putstr_stderr(char *word, char *error_msg);

//utils_print.c
void	print_list(t_cmd *list);
void	print_tab(char **tabl);
void	print_list_env(t_env *list);
void	print_list_tokens(t_tok *list);
void	print_list_commandes(t_cmd *list);
void	print_tab_int(int *tabl);
void	print_message(void);

//utils_free.c
void	free_data(t_data *data);
void	free_list_cmd(t_cmd *liste);
void	free_list_tok(t_tok *lst);
void	free_list_env(t_env *lst);

//utils_free2.c
void	double_free(char *s1, char *s2);
void	free_main(t_data *data);

//utils_str.c
char	*ft_strjoin_char(char *s1, char const s2);

//tools
void	list_open_fds(void);

//programm.c
void	fork_programm(char **input, t_data *data, int fd[4]);
void	exec_programm(t_data *data, char **input, int fd[4]);
bool	check_access_executable(char **input, t_data *data);
//expand_

// env_to_tab.c
char	**env_to_tab(t_env *env);

////////////////////////////////////////////////////////////////////////////////

//redirections

// redir_main.c
bool	redir_heredoc(t_cmd *cmd, t_word *word, t_data *data, int fd[4]);
bool	redir_in(t_word *word, t_cmd *cmd, t_data *data);

//redir_heredoc_read.c
bool	read_heredoc(int fdh, char *oldpwd, char *delimiter);
bool	heredoc_ctrl_c(int fdh, char *oldpwd, char *new_line);

#endif