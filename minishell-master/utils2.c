/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:05:11 by calmouht          #+#    #+#             */
/*   Updated: 2024/01/12 06:06:43 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strspn(char *str, char *accept)
{
	int i;
	while (*str)
	{
		i = 0;
		while (accept[i])
		{
			if (*str == accept[i])
				return 1;
			i++;
		}
		str++;
	}
	return 0;
}

// char *ft_strdup(char *str)
// {
// 	int i;
// 	int len;
// 	char *dup;

// 	i = 0;
// 	len = 0;
// 	while (str[len])
// 		len++;
// 	dup = (char *)malloc(sizeof(char) * (len + 1));
// 	while (str[i])
// 	{
// 		dup[i] = str[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }
