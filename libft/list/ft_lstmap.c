/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 07:37:52 by atu               #+#    #+#             */
/*   Updated: 2023/10/21 11:17:59 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst,	void *(*f)(void *elem), void (*del)(void *))
{
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new == NULL)
		return (NULL);
	if (lst->next != NULL)
	{
		new->next = ft_lstmap(lst->next, f, del);
		if (new->next == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
	}
	return (new);
}
