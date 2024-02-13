#include "../includes/minishell.h"

t_env *ms_env_new(char **envp)
{
	t_env *env;
	char *env_name;
	char *env_value;
	int i;

	i = 0;
	env = (t_env *)malloc(sizeof(t_env));

	while (env)
	{
		env_name = ft_strchr(t_env.varname, '=');
		env_value = ft_strncpy(env_name + 1, d); 
		env = env->next;
		env->next = NULL;
	}
	return (env);
}

char *kmala(char *str, int i)
{
	char *new_str;

	i += 1;
	new_str = (char *)malloc(sizeof(char) * (i + 1));
	
}