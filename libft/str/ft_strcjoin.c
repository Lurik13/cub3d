/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:52:09 by aboyreau          #+#    #+#             */
/*   Updated: 2024/02/02 18:17:25 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcjoin(const char *s1, const char *s2, char c)
{
	int		len;
	char	*new;
	char	*temp;

	len = 1;
	len += ft_strlen(s1);
	len += ft_strchr(s2, c) - s2;
	new = ft_calloc(len, sizeof(char));
	if (new == NULL)
		return (NULL);
	temp = new;
	while (*s1)
	{
		*new = *s1;
		new ++;
		s1++;
	}
	while (*s2 && *s2 != 'c')
	{
		*new = *s2;
		new ++;
		s2++;
	}
	return (temp);
}
