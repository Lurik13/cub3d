/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:19:15 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/12 09:01:17 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "ft_tree.h"
#include "libft.h"

void	test_new(void);
void	test_add_child(void);
void	test_depth(void);
void	test_clear(void);

int	main(void)
{
	ft_printf("\n============= TREES =============\n\n");
	ft_printf("=== ft_treenew ===\n\n");
	test_new();
	ft_printf("=== ft_tree_addchild ===\n\n");
	test_add_child();
	ft_printf("=== ft_treedepth ===\n\n");
	test_depth();
	ft_printf("=== ft_treeclear ===\n\n");
	test_clear();
}

void	test_new(void)
{
	t_tree	*head;

	head = ft_treenew("test");
	assert(head != NULL);
	ft_printf("The element is not NULL");
	assert(ft_strcmp(head->content, "test") == 0);
	ft_printf("\t\t✅\nIts content is \"test\"");
	assert(head->children != NULL);
	ft_printf("\t\t✅\nIts children are not NULL");
	assert(head->children != NULL);
	ft_printf("\t✅\nThere are no children");
	assert(head->children[0] == NULL);
	ft_printf("\t\t✅\n\n");
	free(head->children);
	free(head);
}

void	test_add_child(void)
{
	t_tree	*head;
	t_tree	*newelem1;
	t_tree	*newelem2;

	head = ft_treenew("test");
	newelem1 = ft_treenew("child1");
	newelem2 = ft_treenew("child2");
	ft_treeadd_child(head, newelem1);
	ft_treeadd_child(head, newelem2);
	ft_printf("The head has children");
	assert(head->children[0] != NULL);
	assert(head->children[1] != NULL);
	ft_printf("\t\t\t✅\nThe first child is child1");
	assert(ft_strcmp(head->children[0]->content, "child1") == 0);
	ft_printf("\t\t✅\nThe second child is child2");
	assert(ft_strcmp(head->children[1]->content, "child2") == 0);
	ft_printf("\t\t✅\nThe children array is NULL-terminated");
	assert(head->children[2] == NULL);
	ft_printf("\t✅\n\n");
	free(head->children);
	free(head);
	free(newelem1->children);
	free(newelem1);
	free(newelem2->children);
	free(newelem2);
}

void	test_depth(void)
{
	t_tree	*head;
	t_tree	*one;
	t_tree	*two;

	head = ft_treenew("test");
	one = ft_treenew("one");
	two = ft_treenew("two");
	ft_printf("Depth is 1");
	assert(ft_treedepth(head) == 1);
	ft_printf("\t\t✅\n");
	ft_treeadd_child(head, one);
	ft_printf("Depth is 2");
	assert(ft_treedepth(head) == 2);
	ft_printf("\t\t✅\n");
	ft_treeadd_child(one, two);
	ft_printf("Depth is 3");
	assert(ft_treedepth(head) == 3);
	ft_printf("\t\t✅\n");
	ft_printf("Depth is 0");
	assert(ft_treedepth(NULL) == 0);
	ft_printf("\t\t✅\n");
	ft_printf("Depth is 1");
	head->children[0] = NULL;
	assert(ft_treedepth(head) == 1);
	ft_printf("\t\t✅\n\n");
	free(head->children);
	free(head);
	free(one->children);
	free(one);
	free(two->children);
	free(two);
}

void	test_clear(void)
{
	t_tree	*head;
	t_tree	*one;
	t_tree	*two;
	t_tree	*three;
	t_tree	*four;

	head = ft_treenew("test");
	one = ft_treenew("one");
	two = ft_treenew("two");
	three = ft_treenew("three");
	four = ft_treenew("four");
	ft_treeadd_child(head, one);
	ft_treeadd_child(head, three);
	ft_treeadd_child(one, two);
	ft_treeadd_child(one, four);
	ft_treeclear(&head, NULL);
	ft_printf("Tree is cleared");
	assert(head == NULL);
	ft_printf("\t\t✅\n\n");
}
