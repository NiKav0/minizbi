/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmdgen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 06:38:46 by calmouht          #+#    #+#             */
/*   Updated: 2024/05/11 03:25:45 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*ms_cmdgen(char **cmd)
{
	t_cmd *head = NULL;
	t_cmd *current = NULL;
	int checkpoint = 0;

	int i = 0;
	current = (t_cmd *)malloc(sizeof(t_cmd));
	while (cmd && cmd[i])
	{
		if (ms_ctrlop(cmd[i]) == PIPE || cmd[i + 1] == NULL)
		{
			// printf("check: %d   i: %d\n",checkpoint, i + 1);
				puts(cmd[i]);
			if (cmd[i + 1] == NULL) {
				current->cmd = ft_arrslice(cmd, checkpoint, i + 1);
			}
			else 
				current->cmd = ft_arrslice(cmd, checkpoint, i);
				if (checkpoint == 0)
					head = current;
			checkpoint = i + 1;
			current->next = NULL;
			if (cmd[i + 1] != NULL)
			{
					current->next = (t_cmd *)malloc(sizeof(t_cmd));
					ft_bzero(current->next, sizeof(t_cmd));
					current = current->next;
			}
			i = checkpoint;
		}
		else{
		// printf("hhh %s hhh\n", cmd[i]);
			i++;
		}
		// printf("ggg %s ggg\n", cmd[i]);

	}
	// printf("tab %d\n",i);
	current->count = i;
	head->red = NULL;
	get_redir(&head);
	return head;
}
