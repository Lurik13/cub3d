/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 04:01:08 by atu               #+#    #+#             */
/*   Updated: 2023/10/19 11:16:43 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*nb_to_str(unsigned int n, int neg)
{
	int		n2;
	int		count;
	char	*new;

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

char	*ft_itoa(int n)
{
	int		neg;
	char	*new;

	neg = n < 0;
	if (neg)
		n = -n;
	if (n == 0)
	{
		new = ft_calloc(2, 1);
		if (new != NULL)
			new[0] = '0';
		return (new);
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (nb_to_str(n, neg));
}
