/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:20:32 by atu               #+#    #+#             */
/*   Updated: 2024/01/02 17:20:15 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct s_btree
{
	void			*item;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

typedef void		(*t_applyf)(void *);
typedef int			(*t_comp)(void *, void *);

t_btree				*btree_create_node(void *item);
void				btree_apply_prefix(t_btree *root, t_applyf f);
void				btree_apply_infix(t_btree *root, t_applyf f);
void				btree_apply_suffix(t_btree *root, t_applyf f);
void				btree_insert_data(t_btree **root, void *item, t_comp cmpf);
void				*btree_search_item(t_btree *root, void *data_ref,
						t_comp cmpf);
int					btree_level_count(t_btree *root);

#endif
