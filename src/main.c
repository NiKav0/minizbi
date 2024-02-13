#include "../includes/minishell.h"

int	ms_prompt(t_env *env){
	char *cmd;
	char **lexed;

	cmd = readline("$> ");
	add_history(cmd);
	if (cmd == NULL)
		return (2);
	lexed = ms_parse(cmd);
	(void) lexed;
	(void) env;
	return (0);
}

int main(int argc, char **argv, char **envp){
	// we dont need theses params
	(void) argv;
	(void) argc;
	int cmd_status;
	t_env	*env;

	if (envp == NULL)
		return (EXIT_FAILURE);
	env = ms_env_new(envp);
	while (true) {
		cmd_status = ms_prompt(env);
		if (cmd_status != 0)
			return (cmd_status);
	}
}
