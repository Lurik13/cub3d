/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:52:09 by aboyreau          #+#    #+#             */
/*   Updated: 2023/12/22 20:52:22 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, size_t size)
{
	char	*new;
	char	*temp;

	new = (char *)malloc(ft_strlen(s1) + size + 1);
	if (new == NULL)
		return (NULL);
	temp = new;
	while (*s1)
	{
		*new = *s1;
		new ++;
		s1++;
	}
	while (*s2 && size)
	{
		*new = *s2;
		new ++;
		s2++;
		size--;
	}
	*new = '\0';
	return (temp);
}
