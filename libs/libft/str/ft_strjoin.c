/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:25:58 by atu               #+#    #+#             */
/*   Updated: 2024/03/25 11:16:19 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_str.h"
#include <stdlib.h>
#include <stdarg.h>

char	*ft_strjoin(const char *s1, ...)
{
	int		size;
	va_list	args;
	char	*new;
	char	*next;

	new = ft_strdup(s1);
	if (new == NULL)
		return (NULL);
	va_start(args, s1);
	while (1)
	{
		next = va_arg(args, char *);
		if (next == NULL)
			break ;
		size = ft_strlen(new) + ft_strlen(next) + 1;
		new = ft_grow(new, ft_strlen(new) + 1, size);
		if (new == NULL)
			return (NULL);
		ft_strlcat(new, next, size);
	}
	va_end(args);
	return (new);
}
