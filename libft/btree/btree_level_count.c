/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:09:48 by atu               #+#    #+#             */
/*   Updated: 2024/01/05 03:39:05 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "../libft.h"
#include <stdlib.h>

int	recursive_count(t_btree *node, int depth);

int	btree_level_count(t_btree *root)
{
	return (recursive_count(root, 0));
}

int	recursive_count(t_btree *node, int depth)
{
	int	max;
	int	count;

	if (node == NULL)
		return (depth);
	max = recursive_count(node->left, depth + 1);
	count = recursive_count(node->right, depth + 1);
	if (count > max)
		max = count;
	return (max);
}
