/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:28:51 by calmouht          #+#    #+#             */
/*   Updated: 2024/05/10 01:01:23 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void get_redir(t_cmd **cmd)
{
	t_cmd *head = *cmd;
	int i = 0;
	while(head)
	{
		i = 0;
		while(head->cmd[i])
		{
			head->red = malloc(sizeof(e_type));
			if(!strcmp(head->cmd[i],">") && strcmp(head->cmd[i],">>"))
			{
				head->red->file = head->cmd[i + 1];
				// printf("file %s\n",head->red->file);
				head->red->type = RREDIR;
			}
			else if(!strcmp(head->cmd[i],"<") && strcmp(head->cmd[i],"<<"))
			{
				head->red->file = head->cmd[i - 1];
				// printf("file %s\n",head->red->file);
				head->red->type = LREDIR;
			}
			else if(!strcmp(head->cmd[i],"<<"))
			{
				head->red->file = head->cmd[i - 1];
				// printf("file %s\n",head->red->file);
				head->red->type = HEREDOC;
			}
			else if(!strcmp(head->cmd[i],">>"))
			{
				
				head->red->file = head->cmd[i + 1];
				// printf("file %s\n",head->red->file);
				head->red->type = APPEND;
			}
			i++;
		}
		
		head = head->next;
	}
	
}

void	file_names(t_cmd **cmd)
{
	int i = 0;
	t_cmd *head = *cmd;
	
	while (head->cmd[i] != NULL) 
	{
	  if (strcmp(head->cmd[i], ">") == 0 || strcmp(head->cmd[i], "<") == 0 || strcmp(head->cmd[i], ">>") == 0)
	  {
	    char *filename = head->cmd[i + 1];
	    t_red *new_red = malloc(sizeof(t_red));
		if (strcmp(head->cmd, ">") == 0)
		{
		//   new_red = malloc(sizeof(t_red));
		  new_red->type = RREDIR;
		}
		else if (strcmp(head->cmd, "<") == 0)
		{
		//   new_red = malloc(sizeof(t_red));
		  new_red->type = LREDIR;
		}
		else
		{
		//   new_red = malloc(sizeof(t_red));
		  new_red->type = APPEND;
		}
	    new_red->file = strdup(filename);
		i++;
	  }
	  i++;
	}
}