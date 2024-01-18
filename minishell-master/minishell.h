/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:52:54 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/15 04:03:56 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>

// typedef enum e_redir {
// 	DIR_IN,
// 	DIR_OUT,
// 	DIR_APPRND,
// 	DIR_HERDOC,
// 	NONE
// } redir_type;

// typedef struct s_minishell
// {
// 	char **args;
// 	char *outfile;
// 	char *infile;
// 	char *current_dir;
// 	enum e_redir in_type;
// 	enum e_redir out_type;
// 	 struct s_minishell *next;
// }t_minishell;

// typedef struct s_envp
// {
// 	char *data;
// 	struct s_envp *next;
// } t_envp;

typedef struct s_redir
{
	int type_redir;
	char *file;
	struct s_redir *next;
} t_redir;

typedef struct s_cmnds
{
	char	*cmds;
	char	**args;
	enum e_types	type;
	enum e_state	state;
	t_redir *redirections;
	struct s_cmnds *next;
} t_cmnds;

typedef struct ms_cmd {
	char **cmd;
	msIO input;
	char *inputfile;
	msIO output;
	char *outputfile;
	struct ms_cmd *nxt;
}ms_cmd;
// cat -e < /etc/passwd > zebi
typedef enum msIO {
	NONE,
	HEREDOC,		// <<
	LREDIR,			// <
	RREDIR,			// >
	APPEND,			// >>
};

enum e_state
{
	IN_DQ,
	IN_SQ,
	OUT_DQ,
	OUT_SQ,
};

typedef enum e_types
{
	BACKSLASH_ZERO,
	SPACES,
	PIPES,
	DOLAR_SIGN,
	RED_ONE_LEFT,
	RED_ONE_RIGHT,
	RED_TWO_LEFT,
	RED_TWO_RIGHT,
	ENV,
};

int	ft_strspn(char *str, char *accept);
int			echo_opt(const char *av);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(char *src);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strtok(char *str, char *delim);
void		ft_putstr(char *s);
t_envp		*dup_env(char **envp);
t_envp		*create_node(char *envp);
t_envp		*remove_env_variable(t_envp *data, const char *key);
void	*ft_calloc(size_t count, size_t size);

