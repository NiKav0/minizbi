/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmdgen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 06:38:46 by calmouht          #+#    #+#             */
/*   Updated: 2024/03/27 01:31:44 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// t_cmd	*ms_cmdgen(char **cmd)
// {
// 	int i;
// 	int checkpoint;
// 	t_cmd *head;
// 	t_cmd *current;

// 	head = (t_cmd *)malloc(sizeof(t_cmd));
// 	current = head;
// 	checkpoint = 0;
// 	i = 0;
// 	while (cmd[i] != NULL)
// 	{
// 		if (ms_ctrlop(cmd[i]) == PIPE || cmd[i + 1] == NULL)
// 		{
// 			printf("check: %d   i: %d\n",checkpoint, i);
// 			if (cmd[i + 1] == NULL)
// 				i++;
// 			current->cmd = ft_arrslice(cmd, checkpoint, i);
// 			checkpoint = i + 1;
// 			current->next = (t_cmd *)malloc(sizeof(t_cmd));
// 			current = current->next;
// 			printf("%s\n", current->cmd[i]);
// 			current->next = NULL;
// 		}
// 		i++;
// 	}
	
// 	return (head);
// }

// t_cmd	*ms_cmdgen(char **cmd)
// {
// 	int i;
// 	int checkpoint;
// 	t_cmd *head;
// 	t_cmd *current;

// 	head = (t_cmd *)malloc(sizeof(t_cmd));
// 	current = head;
// 	checkpoint = 0;
// 	i = 0;
// 	while (cmd[i] != NULL)
// 	{
// 		if (ms_ctrlop(cmd[i]) == PIPE || cmd[i + 1] == NULL)
// 		{
// 			printf("check: %d   i: %d\n",checkpoint, i);
// 			if (cmd[i + 1] == NULL)
// 				i++;
// 			current->cmd = ft_arrslice(cmd, checkpoint, i);
// 			checkpoint = i + 1;
// 			if (cmd[i] != NULL) {
// 				current->next = (t_cmd *)malloc(sizeof(t_cmd));
// 				current = current->next;
// 			} else {
// 				current->next = NULL;
// 			}
// 		}
// 		i++;
// 	}
// 	printf("%d\n", i);
// 	return (head);
// }

t_cmd	*ms_cmdgen(char **cmd)
{
	t_cmd *head = NULL;
	t_cmd *current = NULL;
	int checkpoint = 0;

	int i = 0;
	while (cmd && cmd[i]) {
		if (ms_ctrlop(cmd[i]) == PIPE || !cmd[i + 1]) {
			printf("check: %d   i: %d\n",checkpoint, i + 1);
			current = (t_cmd *)malloc(sizeof(t_cmd));
			current->cmd = ft_arrslice(cmd, checkpoint, i + 1);
			if (checkpoint == 0)
				head = current;
			checkpoint = i + 1;
			current->next = NULL;
			i = checkpoint;
		}else
			i++;
	}
	return head;
}
