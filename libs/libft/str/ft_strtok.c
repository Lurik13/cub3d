/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:57:35 by aboyreau          #+#    #+#             */
/*   Updated: 2024/02/14 02:12:09 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdio.h>
#include "../math/math.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*target;
	char		current_token;
	char		*token;
	int			pos;

	pos = 0;
	current_token = '\0';
	if (str != NULL)
		target = str;
	if (*target == '\0')
		return (NULL);
	if (ft_strcontains(delim, target[pos]))
		current_token = target[pos++];
	if (current_token == '\0')
		while (target[pos] && !ft_strcontains(delim, target[pos]))
			pos++;
	else
		while (target[pos] && target[pos] != current_token)
			pos++;
	token = ft_substr(target, 0, pos + (current_token != '\0'));
	target += (int) ft_min(pos, ft_strlen(target));
	if (current_token != '\0' && *target)
		target += 1;
	return (token);
}
