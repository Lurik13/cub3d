/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:42:50 by aboyreau          #+#    #+#             */
/*   Updated: 2024/02/02 20:46:35 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int	ft_strendswith(char *str, char *end)
{
	int	i;
	int	endlen;
	int	strlen;

	i = 0;
	endlen = ft_strlen(end);
	strlen = ft_strlen(str);
	while (i + endlen < strlen)
	{
		i++;
	}
	return (ft_strcmp(str + i, end) == 0);
}
