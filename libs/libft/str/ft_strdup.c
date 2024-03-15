/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:01:34 by atu               #+#    #+#             */
/*   Updated: 2024/03/03 11:49:26 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

char	*ft_strdup(const char *src)
{
	int		strlen;
	char	*dup;

	if (src == NULL)
		return (NULL);
	strlen = ft_strlen(src) + 1;
	dup = malloc(strlen * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (strlen--)
	{
		dup[strlen] = src[strlen];
	}
	return (dup);
}
