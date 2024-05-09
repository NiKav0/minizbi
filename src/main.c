/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 03:18:08 by calmouht          #+#    #+#             */
/*   Updated: 2024/05/08 23:17:07 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ms_prompt(t_env **env)
{
	char	*cmd;
	char	**lexed;
	t_cmd	*cmd2;

	cmd = readline("$> ");
	add_history(cmd);
	if (cmd == NULL)
		return (2);
	lexed = ms_parse(cmd);
	ms_rendercmd(lexed, *env);
	cmd2 = ms_cmdgen(lexed);
	exec_cmd(env, cmd2);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		cmd_status;
	t_env	*env;

	(void)argv;
	(void)argc;
	if (envp == NULL)
		return (EXIT_FAILURE);
	env = ms_env_new(envp);
	while (true)
	{
		cmd_status = ms_prompt(&env);
		if (cmd_status != 0)
			return (cmd_status);
		// system("leaks minishell");
	}
}
