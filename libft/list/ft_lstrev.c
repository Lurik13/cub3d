/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:10:54 by aboyreau          #+#    #+#             */
/*   Updated: 2024/01/20 19:02:00 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

static	void	rev(t_list *lst)
{
	t_list	*next;

	next = lst->next;
	if (next == NULL)
		return ;
	lst->next = NULL;
	rev(next);
	next->next = lst;
	lst = next;
}

void	ft_lstrev(t_list **lst)
{
	t_list	*temp;

	if (*lst == NULL)
		return ;
	temp = *lst;
	*lst = ft_lstlast(*lst);
	rev(temp);
}
