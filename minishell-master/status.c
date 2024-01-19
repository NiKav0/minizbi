/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 07:10:08 by calmouht          #+#    #+#             */
/*   Updated: 2024/01/19 08:25:45 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	word_type(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '>' && cmd[i + 1] == '>')
		return (OUT_REDIR);
		if (cmd[i] == '>' && cmd[i + 1] != '>')
		return (APPEND);
	}
}