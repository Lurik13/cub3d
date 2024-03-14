/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 01:56:34 by aboyreau          #+#    #+#             */
/*   Updated: 2024/01/24 09:39:42 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Allocates (with malloc(3)) and returns a new node. The member variable
 * `content` is initialized with the value of the parameter `content`.
 * The variable `next` is initialized to `NULL`.
 * @param content The content to create the node with.
 * @return The new node.
 */
t_list				*ft_lstnew(void *content);

/**
 * @brief Adds the node `new` at the beginning of `list`.
 * @param list The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 */
void				ft_lstadd_front(t_list **lst, t_list *newelem);

/**
 * @brief Counts the number of nodes in a list.
 * @param list The beginning of the list.
 * @return The length of the list.
 */
int					ft_lstsize(t_list *list);

/**
 * @brief Returns the last node of the list.
 * @param list The beginning of the list.
 * @return Last node of the list.
 */
t_list				*ft_lstlast(t_list *list);

/**
 * @brief Adds the node `new` at the end of the list.
 * @param list The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 */
void				ft_lstadd_back(t_list **list, t_list *newelem);

/**
 * @brief Takes as a parameter a node and frees the memory of the node’s content
 * using the function `del_fun` given as a parameter and free the node. The
 * memory of `next` must not be freed.
 * @param list The node to free.
 * @param del_fun The address of the function used to delete the content.
 */
void				ft_lstdelone(t_list *list, void (*del_fun)(void *));

/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function `del_fun` and free(3). Finally, the pointer to the list
 * must be set to `NULL`.
 * @param list The address of a pointer to a node.
 * @param del_fun The address of the function used to delete the content of the
 * node.
 */
void				ft_lstclear(t_list **list, void (*del_fun)(void *));

/**
 * @brief Iterates the list `list` and applies the function `f` on the content
 * of each node.
 * @param list The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 */
void				ft_lstiter(t_list *list, void (*f)(void *));

/**
 * @brief Iterates the list `list` and applies the function `f` on the content
 * of each node. Creates a new list resulting of the successive applications of
 * the function `f`. The `del_fun` function is used to delete the content of a
 * node if needed.
 * @param list The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del_fun The address of the function used to delete the content of a
 * node if needed.
 * @return The new list or `NULL` if the allocation fail.
 */
t_list				*ft_lstmap(t_list *list, void *(*f)(void *),
						void (*del_fun)(void *));

/**
 * @brief Reverses a list.
 * @param lst A list.
 * @return A pointer to the new start of the list after reversing it.
 */
void				ft_lstrev(t_list **lst);

/**
 * @brief Creates a new list from a tab.
 * @param tab An array that will be converted to a list.
 * @param size The size of the array.
 * @return A pointer to the start of the new list.
 */
t_list				*ft_lst_from_tab(void *tab, int size);

/**
 * @brief Creates a new tab from a list.
 * @param lst A list that will be converted to an array.
 * @return An array filled with the content of the list.
 */
void				**ft_lst_to_tab(t_list *lst);

#endif
