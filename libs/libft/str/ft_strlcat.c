/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:37:07 by atu               #+#    #+#             */
/*   Updated: 2023/10/19 13:10:21 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	const char	*odst;
	const char	*osrc;
	size_t		dsize;
	size_t		dlen;

	odst = dst;
	osrc = src;
	dsize = n;
	while (dsize-- != 0 && *dst)
		dst++;
	dlen = dst - odst;
	dsize = n - dlen;
	if (dsize-- == 0)
		return (dlen + ft_strlen(src));
	while (*src)
	{
		if (dsize != 0)
		{
			*dst++ = *src;
			dsize--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
