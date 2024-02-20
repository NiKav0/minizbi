/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 03:18:27 by calmouht          #+#    #+#             */
/*   Updated: 2024/02/19 03:43:31 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	ms_errors(char **cmd)
{
	int i;

	i = 0;
	while (cmd[i + 1])
	{
		if (ms_ctrloop(cmd[i]) != NONE && ms_ctrloop(cmd[i + 1]) != NONE)
		{
			printf("Syntax error near expected token `%s\'", cmd[i + 1]);
			return (false);
		}
	}
	if (ms_ctrloop(cmd[i + 1]) != NONE)
	{
		printf("Syntax error near unexpected token `newline\'");
		return (false);
	}
}