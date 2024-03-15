/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:31:14 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/12 09:34:18 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"
#include "libft.h"

void	ft_treeiter(t_tree *tree, void (*f)(void *))
{
	int	i;

	i = 0;
	if (f)
		f(tree->content);
	while (tree->children[i])
		ft_treeiter(tree->children[i++], f);
}
