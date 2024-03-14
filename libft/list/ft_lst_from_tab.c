/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_from_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:30:35 by aboyreau          #+#    #+#             */
/*   Updated: 2024/02/06 00:10:54 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lst_from_tab(void *tab, int size)
{
	int		i;
	t_list	*new;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(&new, ft_lstnew(tab + i));
		i++;
	}
	return (new);
}
