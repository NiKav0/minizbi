#include "../includes/minishell.h"
#include <stdio.h>

char *ft_strreplace(char *src, char *dst, char *replacement)
{
	char *ptr;


		if (strstr(src, dst))
		{
			ptr = malloc(sizeof(char) * (ft_strlen(src) - ft_strlen(dst) + ft_strlen(replacement) + 1));
			ft_strlcpy(ptr, src, strstr(src, dst) - src + 1);
			ft_strlcat(ptr, replacement, ft_strlen(ptr) + ft_strlen(replacement) + 1);
			ft_strlcat(ptr, strstr(src,dst)+ ft_strlen(dst), ft_strlen(ptr) + ft_strlen(strstr(src,dst)+ ft_strlen(dst)) + 1);
			src++;
		}
		else
			ptr = ft_strdup(src);
	return (ptr);
}

char *ft_strreplace_all(char *src, char *dst, char *replacement)
{
	char *ptr;
	char *tmp;

	ptr = ft_strdup(src);
	while (strstr(ptr, dst))
	{
		tmp = ft_strreplace(ptr, dst, replacement);
		free(ptr);
		ptr = tmp;
	}
	return (ptr);
}
