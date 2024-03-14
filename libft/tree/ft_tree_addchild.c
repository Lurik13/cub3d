/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_addchild.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:01:38 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/12 08:19:09 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_tree.h"

void	ft_treeadd_child(t_tree *tree, t_tree *newelem)
{
	int	count;

	count = 0;
	if (tree == NULL)
		return ;
	while (tree->children[count])
		count++;
	tree->children = ft_grow(tree->children, count * sizeof(void *),
			(count + 1) * sizeof(void *));
	tree->children[count] = newelem;
}
