/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 04:01:08 by atu               #+#    #+#             */
/*   Updated: 2024/03/14 05:34:08 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*nb_to_str(unsigned int n, int neg)
{
	unsigned int	n2;
	int				count;
	char			*new;

	n2 = n;
	count = 0;
	while (n2 != 0)
	{
		n2 /= 10;
		count++;
	}
	new = ft_calloc(count + neg + 1, 1);
	if (new == NULL)
		return (NULL);
	while (n != 0)
	{
		count--;
		new[count + neg] = n % 10 + '0';
		n /= 10;
	}
	if (neg == 1)
		new[0] = '-';
	return (new);
}

char	*ft_uitoa(unsigned int n)
{
	char	*new;

	if (n == 0)
	{
		new = ft_calloc(2, 1);
		if (new != NULL)
			new[0] = '0';
		return (new);
	}
	return (nb_to_str(n, 1));
}
