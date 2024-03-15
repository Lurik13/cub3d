/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:47:37 by atu               #+#    #+#             */
/*   Updated: 2024/01/23 05:37:11 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	contains(const char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	int		i;
	char	*new;

	while (contains(*s, set))
		s++;
	i = ft_strlen(s) - 1;
	while (contains(*(s + (i * (i >= 0))), set))
		i--;
	new = ft_substr(s, 0, i + 1);
	if (new == NULL)
		return (NULL);
	return (new);
}
