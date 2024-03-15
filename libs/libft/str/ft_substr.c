/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:15:30 by atu               #+#    #+#             */
/*   Updated: 2023/10/21 10:47:21 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	strlen;
	char	*new;

	if (s == NULL)
		return (NULL);
	strlen = ft_strlen(s);
	if (strlen <= start)
		len = 0;
	else if (strlen <= start + len)
		len = strlen - start;
	new = (char *)ft_calloc((len + 1), sizeof(char));
	if (new != NULL && len > 0)
		ft_strlcpy(new, s + start, len + 1);
	return (new);
}
