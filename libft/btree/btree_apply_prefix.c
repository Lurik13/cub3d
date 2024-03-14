/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:20:26 by atu               #+#    #+#             */
/*   Updated: 2023/09/09 14:50:24 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, t_applyf f)
{
	f(root->item);
	if (root->left)
		btree_apply_prefix(root->left, f);
	if (root->right)
		btree_apply_prefix(root->right, f);
}
