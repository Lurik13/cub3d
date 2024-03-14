/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 05:21:37 by atu               #+#    #+#             */
/*   Updated: 2023/10/18 16:44:30 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	i = 0;
	new = ft_strdup(s);
	if (new == NULL)
		return (NULL);
	while (new[i])
	{
		new[i] = f(i, new[i]);
		i++;
	}
	return (new);
}
