/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:50:35 by atu               #+#    #+#             */
/*   Updated: 2023/10/21 11:15:11 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	**fill_tab(char **tab, char *s2, char c)
{
	int		count;
	char	*next;

	count = 1;
	next = ft_strchr(s2, c);
	if (next == NULL)
		next = ft_strchr(s2, '\0');
	tab[0] = ft_substr(s2, 0, next - s2);
	while (*s2 && *(s2 + 1))
	{
		if (*s2 == c && *(s2 + 1) != c)
		{
			next = ft_strchr(s2 + 1, c);
			if (next == NULL)
				next = ft_strchr(s2 + 1, '\0');
			tab[count] = ft_substr(s2, 1, next - s2 - 1);
			count++;
		}
		s2++;
	}
	tab[count] = NULL;
	return (tab);
}

static char	**complete_tab(char *s2, int count, char c)
{
	char	**tab;

	tab = malloc((count + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	if (*s2 == '\0')
	{
		tab[0] = NULL;
		return (tab);
	}
	if (count == 1)
	{
		tab[0] = ft_strdup(s2);
		tab[1] = NULL;
		return (tab);
	}
	return (fill_tab(tab, s2, c));
}

char	**handle_empty(void)
{
	char	**tab;

	tab = malloc(1 * sizeof(char *));
	if (tab != NULL)
		tab[0] = NULL;
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	int		count;
	char	**tab;
	char	*s2;
	char	*s3;

	if (ft_strlen(s) == 0)
		return (handle_empty());
	count = 1;
	while (*s == c)
		s++;
	s2 = ft_calloc(2, 1);
	if (s2 == NULL)
		return (NULL);
	s2[0] = c;
	s3 = ft_strtrim(s, s2);
	free(s2);
	while (*s && *(s + 1))
	{
		if (*s == c && *(s + 1) != c)
			count++;
		s++;
	}
	tab = complete_tab(s3, count, c);
	free(s3);
	return (tab);
}
