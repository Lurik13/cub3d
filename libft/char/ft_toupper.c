/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:48:45 by atu               #+#    #+#             */
/*   Updated: 2023/10/05 05:20:58 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_toupper(int c)
{
	int	diff;

	diff = 'A' - 'a';
	if (c >= 'a' && c <= 'z')
		return (c + diff);
	return (c);
}