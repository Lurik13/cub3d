/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:24:00 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/03 12:43:09 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strreplace(char *str, char *pattern, char *replacement)
{
	char	*new;
	char	*newnew;
	char	*newnewnew;
	char	*toreplace;

	newnewnew = NULL;
	toreplace = ft_strnstr(str, pattern, ft_strlen(str));
	while (toreplace)
	{
		new = ft_substr(str, 0, toreplace - str);
		newnew = ft_strjoin(new, replacement, NULL);
		free(new);
		new = newnewnew;
		newnewnew = ft_strjoin(newnew, toreplace + ft_strlen(pattern), NULL);
		free(new);
		free(newnew);
		str = newnewnew;
		toreplace = ft_strnstr(str, pattern, ft_strlen(str));
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*start = ("$1 test $1\n");
	char	*pattern = "$1";
	char	*replacement = "des leaks";

	char	*replaced = ft_strreplace(start, pattern, replacement);
	printf("%s", replaced);
	free(replaced);
}
*/
