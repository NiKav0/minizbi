#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>

typedef enum 
{
	NONE,
	HEREDOC,	//<<
	LREDIR,		// <
 	RREDIR,		// >
 	APPEND,		// >>
}e_type;

typedef struct	ms_cmd
{
	char **cmd;
	e_type	input;
	char	*infile;
	e_type	output;
	char *outfile;
	struct s_cmd *next;
}t_cmd;


typedef struct t_env
{
	char *varname;
	char *value;
	struct t_env *next;
}t_env;



#endif
