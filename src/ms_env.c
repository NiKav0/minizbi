#include "../includes/minishell.h"

t_env *ms_env_new(char **envp)
{
	t_env *env;
	t_env *head;
	int i;

	i = 0;
	head = (t_env *)malloc(sizeof(t_env));
	env = head;
	while (envp[i])
	{
		env->varname = ft_strldup(envp[i], ft_strchr(envp[i], '=') - envp[i]);
		env->value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		env->next = (t_env *)malloc(sizeof(t_env));
		env = env->next;
		i++;
	}
	return (env);
}

int	node_count(t_env *env)
{
	int i;

	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
}