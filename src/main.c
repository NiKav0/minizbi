#include "../includes/minishell.h"

int	ms_prompt(){
	char *cmd;

	cmd = readline("$> ");
	add_history(cmd);
	if (cmd == NULL)
		return (2);
	return (0);
}

int main(int argc, char **argv, char **envp){
	// we dont need theses params
	(void) argv;
	(void) argc;
	int cmd_status;
	if (envp == NULL)
		return (EXIT_FAILURE);
	while (true) {
		cmd_status = ms_prompt();
		// parsing --> error handling --> expansion -> unquoting
		// execution
		if (cmd_status != 0)
			return (cmd_status);
	}
}
