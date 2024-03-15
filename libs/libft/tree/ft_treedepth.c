/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedepth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 06:05:10 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/12 08:48:38 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_tree.h"
#include "math/math.h"

int	ft_treedepth(t_tree *tree)
{
	int	i;
	int	max;

	if (tree == NULL)
		return (0);
	i = 0;
	max = 1;
	while (tree->children[i])
		max = 1 + ft_max(max, ft_treedepth(tree->children[i++]));
	return (max);
}
