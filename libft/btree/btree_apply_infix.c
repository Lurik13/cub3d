/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:56:55 by atu               #+#    #+#             */
/*   Updated: 2023/09/09 15:02:45 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, t_applyf f)
{
	if (root->left)
		btree_apply_infix(root->left, f);
	f(root->item);
	if (root->right)
		btree_apply_infix(root->right, f);
}
