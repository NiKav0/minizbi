/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calmouht <calmouht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 05:46:15 by calmouht          #+#    #+#             */
/*   Updated: 2024/05/05 06:25:12 by calmouht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exits(int code)
{
	if (code == 1)
	{
		printf("syntax error near unexpected token `<'");
		exit(0);
	}
	if (code == 2)
	{
		printf("syntax error near unexpected token `newline'");
		exit (0);
	}
}