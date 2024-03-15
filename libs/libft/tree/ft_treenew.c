/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 05:57:29 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/12 06:26:06 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_tree.h"

t_tree	*ft_treenew(void *content)
{
	t_tree	*new;

	new = ft_calloc(1, sizeof(t_tree));
	new->content = content;
	new->children = ft_calloc(1, sizeof(void *));
	return (new);
}
