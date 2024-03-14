/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 01:56:34 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/12 08:20:20 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H

typedef struct s_tree
{
	void			*content;
	struct s_tree	**children;
}					t_tree;

/**
 * @brief Allocates (with malloc(3)) and returns a new node. The member variable
 * `content` is initialized with the value of the parameter `content`.
 * The variable `children` is initialized to a NULL-terminated array of children.
 * @param content The content to create the node with.
 * @return The new node.
 */
t_tree				*ft_treenew(void *content);

/**
 * @brief Counts the depth of a tree.
 * @param tree The beginning of the tree.
 * @return The depth of the tree.
 */
int					ft_treedepth(t_tree *tree);

/**
 * @brief Adds the node `new` to the children of the node  `tree`.
 * @param tree The address of a pointer to a tree node.
 * @param new The address of a pointer to the node to be added to the tree's
 * children.
 */
void				ft_treeadd_child(t_tree *tree, t_tree *newelem);

/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function `del_fun` and free(3). Finally, the pointer to the tree
 * must be set to `NULL`.
 * @param tree The address of a pointer to a node.
 * @param del_fun The address of the function used to delete the content of the
 * node.
 */
void				ft_treeclear(t_tree **tree, void (*del_fun)(void *));

/**
 * @brief Iterates the tree `tree` and applies the function `f` on the content
 * of each node.
 * @param tree The address of a pointer to a node.
 * @param f The address of the function used to iterate on the tree.
 */
void				ft_treeiter(t_tree *tree, void (*f)(void *));

/**
 * @brief Iterates the tree `tree` and applies the function `f` on the content
 * of each node. Creates a new tree resulting of the successive applications of
 * the function `f`. The `del_fun` function is used to delete the content of a
 * node if needed.
 * @param tree The address of a pointer to a node.
 * @param f The address of the function used to iterate on the tree.
 * @param del_fun The address of the function used to delete the content of a
 * node if needed.
 * @return The new tree or `NULL` if the allocation fail.
 */
t_tree				*ft_treemap(t_tree *tree, void *(*f)(void *),
						void (*del_fun)(void *));

#endif
