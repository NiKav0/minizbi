/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 03:18:27 by calmouht          #+#    #+#             */
/*   Updated: 2024/05/16 23:52:47 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	ms_errors(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i + 1])
	{
		if (ms_ctrlop(cmd[i]) != NONE && ms_ctrlop(cmd[i + 1]) != NONE)
		{
			ft_putstr_fd("minishell: syntax error\n", 2);
			return (false);
		}
		i++;
	}
	if (ms_ctrlop(cmd[i + 1]) != NONE)
	{
		ft_putstr_fd("minishell: syntax error\n", 2);
		return (false);
	}
	return (true);
}
