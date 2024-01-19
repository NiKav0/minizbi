/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 07:07:30 by calmouht          #+#    #+#             */
/*   Updated: 2024/01/19 07:10:57 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	skip_space(char *str)
{
	int		i;
	int		opmax;
	int		counter;
	char	quote_mark;

	i = 0;
	quote_mark = str[i];
	opmax = 2;
	counter = 0;
	while (str[i] == quote_mark && str[i] != '\0' && counter++ < opmax)
		i++;
	return (i);
}

static int	ft_length(char *str)
{
	char	quote_mark;
	int		i;

	i = 0;
	if (str[i] == '>' || str[i] == '<' || str[i] == '|')
		i += skip_space(str);
	else
	{
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != '>'
			&& str[i] != '<' && str[i] != '|')
		{
			if (str[i] == '\"' || str[i] == '\'')
			{
				quote_mark = str[i++];
				while (str[i] != quote_mark && str[i] != '\0')
					i++;
			}
			i++;
		}
	}
	return (i);
}

static int	ft_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] != '\0')
			count++;
		i += ft_length(&str[i]);
	}
	return (count);
}

char	**ms_split(char *cmd)
{
	char	**splitted;
	int		j;
	int		i;
	int		len;

	splitted = (char **)calloc((ft_count(cmd) + 1), sizeof(char *));
	i = 0;
	j = 0;
	while (cmd[i] != '\0')
	{
		while ((cmd[i] == ' ' || cmd[i] == '\t') && cmd[i] != '\0')
			i++;
		if (cmd[i] == '\0')
			break ;
		len = ft_length(&cmd[i]);
		splitted[j] = (char *)malloc(len + 1);
		if (!splitted[j])
		{
			while (j > 0)
			{
				free(splitted[--j]);
			}
			free(splitted);
			return (NULL);
		}
		strncpy(splitted[j++], &cmd[i], len);
		splitted[j - 1][len] = '\0';
		i += len;
	}
	return (splitted);
}

int	main(void)
{
	char *arr = "mohammed > ><> >>> ll\"ah wer|ew\"  e |\trw ";
	char **ptr = ms_split(arr);
	int i = 0;
	while (ptr[i])
	{
		printf("%s\n", ptr[i]);
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}