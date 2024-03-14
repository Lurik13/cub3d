/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:13:19 by atu               #+#    #+#             */
/*   Updated: 2023/09/10 22:19:26 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, t_comp cmpf)
{
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf((*root)->item, item) >= 0)
	{
		if ((*root)->right == NULL)
			(*root)->right = btree_create_node(item);
		else
			btree_insert_data((t_btree **) &(*root)->right, item, cmpf);
	}
	else
	{
		if ((*root)->left == NULL)
			(*root)->left = btree_create_node(item);
		else
			btree_insert_data((t_btree **) &(*root)->left, item, cmpf);
	}
}
