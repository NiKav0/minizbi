/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:28:51 by calmouht          #+#    #+#             */
/*   Updated: 2024/05/11 01:06:26 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int t_strlen(char **str)
{
	int i = 0;
	int size = 0;
	while(str[i])
	{
		size += ft_strlen(str[i]);
		i++;
	}
	return size;

}
char **tarray_copy(char **a)
{
	char **cpy = malloc(sizeof(char *) * t_strlen(a));
	int i = 0;
	while(a[i])
	{
		cpy[i] = ft_strdup(a[i]);
		i++;
	}
	cpy[i] = NULL;
	return cpy;
}

void get_new_args(t_cmd **cmd)
{
	t_cmd *head = *cmd;
	char *tmp = NULL;
	int i = 0;
	while(head)
	{
		if(head->red)
		{ 
			while(head->cmd && head->cmd[i])
			{
				if(head->cmd[i] && (!strcmp(head->cmd[i],">>") || !strcmp(head->cmd[i],">") || !strcmp(head->cmd[i],"<<") || !strcmp(head->cmd[i],"<")))
				{
					tmp = head->cmd[i];
					head->cmd[i] = NULL;
					head->args = tarray_copy(head->cmd);
					head->cmd[i] = tmp; 
					break;
				}
				i++;
			}
			// printf("has a red inside code pass \n");
		}
		else
		{
			// printf("else \n");
			head->args = tarray_copy(head->cmd);
		}
		// fe had ster gha bdelt cmd b args bash n testy makhnach nkhdmo hka khask tsift args l serghini o tfreeeyi **cmd o **args
		
		head->cmd = head->args;
		// printf("pass first head \n");
		head = head->next;
	}
}

void printlist(t_cmd **head)
{
	t_cmd *curr;
	curr = *head;
	int i = 0;
	while (curr)
	{
		while (i < curr->count)
		{
			if (ms_ctrlop(curr->cmd[i]) == RREDIR && (ms_ctrlop(curr->cmd[i + 1]) != RREDIR
					|| ms_ctrlop(curr->cmd[i + 1]) == RREDIR))
				exits(2);
			if (ms_ctrlop(curr->cmd[i]) == LREDIR && (ms_ctrlop(curr->cmd[i + 1]) != LREDIR
				|| ms_ctrlop(curr->cmd[i + 1]) == LREDIR))
				exits(2);
			if (ms_ctrlop(curr->cmd[i]) == PIPE && (ms_ctrlop(curr->cmd[i + 1]) != PIPE
				|| ms_ctrlop(curr->cmd[i + 1]) == PIPE))
				exits(2);
			if (ms_ctrlop(curr->cmd[i]) == HEREDOC && (ms_ctrlop(curr->cmd[i + 1]) != HEREDOC
				|| ms_ctrlop(curr->cmd[i + 1]) == HEREDOC))
				exits(2);
			if (ms_ctrlop(curr->cmd[i]) == APPEND && (ms_ctrlop(curr->cmd[i + 1]) != APPEND
				|| ms_ctrlop(curr->cmd[i + 1]) == APPEND))
				exits(2);
			i++;
		}
		i = 0;
		curr = curr->next;
	}
}

void get_redir(t_cmd **cmd)
{
	// printf("get redir\n");
	t_cmd *head = *cmd;
	printlist(cmd);
	int i = 0;
	while(head)
	{
		i = 0;
		while(head->cmd[i])
		{
			// head->red = NULL;
			
			if ((!strcmp((head)->cmd[i],">") || !strcmp((head)->cmd[i],"<") ) && head->count == 1)
			{
				printf("idkfih\n");
				exit(1);
				/* code */
			}
			// printf("%d %d\n", head->count , i);
			if ((!strcmp((head)->cmd[i],">") || !strcmp((head)->cmd[i],"<") ) && !(head)->cmd[i+1])
			{
				printf("tabnk\n");
				exit(1);

				/* code */
			}
			
			if(!strcmp((head)->cmd[i],">") && strcmp(head->cmd[i],">>"))
				{	
					head->red = malloc(sizeof(t_red));
					head->red->file = ft_strdup(head->cmd[i + 1]);
					head->red->type = RREDIR;
					head->red->next  = NULL;
				}
			else if(!strcmp(head->cmd[i],"<") && strcmp(head->cmd[i],"<<"))
				{
					head->red = malloc(sizeof(t_red));
					head->red->file = ft_strdup(head->cmd[i + 1]);
					// printf("file %s\n",head->red->file);
					head->red->type = LREDIR;
					head->red->next  = NULL;
				}

			else if(!strcmp(head->cmd[i],"<<"))
				{
					head->red = malloc(sizeof(t_red));
					head->red->file = ft_strdup(head->cmd[i + 1]);
					// printf("file %s\n",head->red->file);
					head->red->type = HEREDOC;
					head->red->next  = NULL;
				}
			else if(!strcmp(head->cmd[i],">>"))
				{
					head->red = malloc(sizeof(t_red));
					head->red->file = ft_strdup(head->cmd[i + 1]);
					// printf("file %s\n",head->red->file);
					head->red->type = APPEND;
					head->red->next  = NULL;
				}
			i++;
		}
		head = head->next;
	}
	// printf("passed the fisrt pasrt \n");
	get_new_args(cmd);
	
}
