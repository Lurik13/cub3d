/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 07:19:41 by atu               #+#    #+#             */
/*   Updated: 2023/10/19 14:49:10 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *alist, void (*del)(void*))
{
	t_list	*tmp;

	if (alist == NULL)
		return ;
	tmp = alist->next;
	del(alist->content);
	free(alist);
	alist = tmp;
}
