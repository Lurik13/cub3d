/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:54:16 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/12 08:57:11 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_tree.h"

void	ft_treeclear(t_tree **tree, void (*f)(void *))
{
	int	i;

	i = 0;
	if (*tree == NULL)
		return ;
	while ((*tree)->children[i])
	{
		ft_treeclear(&(*tree)->children[i], f);
		i++;
	}
	if (f != NULL)
		f((*tree)->content);
	free((*tree)->children);
	free(*tree);
	*tree = NULL;
}
