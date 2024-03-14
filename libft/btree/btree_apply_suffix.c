/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:59:39 by atu               #+#    #+#             */
/*   Updated: 2023/09/09 15:02:07 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, t_applyf f)
{
	if (root->left)
		btree_apply_suffix(root->left, f);
	if (root->right)
		btree_apply_suffix(root->right, f);
	f(root->item);
}
