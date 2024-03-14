/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 07:29:11 by atu               #+#    #+#             */
/*   Updated: 2023/10/21 10:24:22 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **alist, void (*del)(void *))
{
	t_list	*next;

	next = NULL;
	if (*alist)
		next = (*alist)->next;
	ft_lstdelone(*alist, del);
	*alist = NULL;
	if (next)
		ft_lstclear(&next, del);
}
