/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:53:19 by atu               #+#    #+#             */
/*   Updated: 2023/09/11 14:07:04 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, t_comp cmpf)
{
	t_btree	*found;

	if (root == NULL)
		return (NULL);
	found = btree_search_item(root->left, data_ref, cmpf);
	if (found != NULL)
		return (found);
	if (cmpf(root->item, data_ref) == 0)
		return (root);
	found = btree_search_item(root->right, data_ref, cmpf);
	if (found != NULL)
		return (found);
	return (NULL);
}
