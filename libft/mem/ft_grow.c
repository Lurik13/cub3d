/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:44:41 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/10 08:04:05 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_grow(void *previous, size_t oldsize, size_t size)
{
	void	*new;

	new = ft_calloc(size, sizeof(void *));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, previous, oldsize);
	free(previous);
	return (new);
}
