/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 07:18:59 by calmouht          #+#    #+#             */
/*   Updated: 2024/01/18 08:21:18 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int is_w_space(char c)
{
    return (c == ' ' || c == '\t');
}

int is_s_char(char c) 
{
    return (c == '|' || c == '>' || c == '<' || c == '\'' || c == '\"' || c == '$');
}

int count(char *str)
{
    int i;
    int counter;
    char quote_mark;;

    i = 0;
    counter = 0;
    while (str[i])
    {
        while (str[i] && is_w_space(str[i]))
            i++;
        if (str[i] == '\'' || str[i] == '\"')
        {
            quote_mark = str[i++];
            while (str[i] && str[i] != quote_mark)
            {
                counter++;
                i++;
            }
            if (str[i] == quote_mark)
                i++;
        }
        else
        {
            while (str[i] && !is_w_space(str[i]) && !is_s_char(str[i]))
                i++;
        }
        counter++;
    }
    return (counter);
}

char *allocate(char *str)
{
    int i;
    char quote_mark;
    
    i = 0;
    if (str[i] == '\'' || str[i] == '\"')
    {
         quote_mark = str[i++];
         while (str[i] && str[i] != quote_mark)
             i++;
         if (str[i] == quote_mark)
             i++;
     }
     else if (is_s_char(str[i]))
            i++;
     else
     {
         while (str[i] && !is_w_space(str[i]) && !is_s_char(str[i]))
             i++;
     }
     char *word = (char *)malloc(sizeof(char) * (i + 1));
     if (!word)
         return NULL;
     i = 0;
     if (str[i] == '\'' || str[i] == '\"')
     {
         char quote_mark = str[i++];
         while (str[i] && str[i] != quote_mark)
         {
             word[i - 1] = str[i];
             i++;
         }
         if (str[i] == quote_mark)
             i++;
     }
     else if (is_s_char(str[i]))
        word[i++] = str[i];
     else
     {
         while (str[i] && !is_w_space(str[i]) && !is_s_char(str[i]))
         {
             word[i] = str[i];
             i++;
         }
     }
     word[i] = '\0';
     return word;
}

char **ms_split(char *cmd)
{
    int i;
    int j;
    int len;
    char **ptr;

	i = 0;
	j = 0;
	len = count(cmd);
	ptr = (char **)malloc(sizeof(char *) * (len + 1));
    if (!ptr)
        return NULL;
    while (cmd[i])
	{
        while (cmd[i] && is_w_space(cmd[i]))
            i++;
        ptr[j] = allocate(&cmd[i]);
        if (!ptr[j])
        {
            while (j > 0)
                free(ptr[--j]);
            free(ptr);
            return NULL;
        }
        j++;
        while (cmd[i] && !is_w_space(cmd[i]) && !is_s_char(cmd[i]))
            i++;
    }
    ptr[len] = NULL;
    return (ptr);
}

// TODO :
// handle more than one redirection `echo >>> zebi`
// handle opposite redirections >><
// mhm double everything osf zebi hoa lmo9adas:w
// handle double quotes

int	main()
{
	char *arr = "  w e h>hh";
	char **ptr = ms_split(arr);
	int i = 0;
	while(ptr[i])
	{
		printf("%s\n", ptr[i]);
		i++;
	}
}