/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:30:35 by aboyreau          #+#    #+#             */
/*   Updated: 2024/01/29 13:42:15 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "../libft.h"

void	**ft_lst_to_tab(t_list *lst)
{
	int		i;
	int		size;
	void	**array;

	i = 0;
	size = ft_lstsize(lst);
	array = ft_calloc(size, sizeof(void *));
	if (array != NULL)
	{
		while (lst != NULL)
		{
			if (lst->content)
				array[i] = ft_strdup(lst->content);
			else
				array[i] = NULL;
			lst = lst->next;
			i++;
		}
	}
	return (array);
}
