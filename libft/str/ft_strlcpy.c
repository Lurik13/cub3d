/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:18:01 by aboyreau          #+#    #+#             */
/*   Updated: 2023/10/19 13:53:21 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*osrc;
	size_t		nleft;

	osrc = src;
	nleft = size;
	if (nleft != 0)
	{
		while (--nleft != 0)
		{
			*dst++ = *src++;
			if (*(dst - 1) == '\0')
				break ;
		}
	}
	if (nleft == 0)
	{
		if (size != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - osrc - 1);
}
