/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:05:39 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/10 10:24:24 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_parse_args(char *str, char *flagset)
{
	int	flags;
	int	b_index;

	flags = 0;
	b_index = 1;
	while (*flagset)
	{
		if (ft_strcontains(str, *flagset))
			flags |= b_index;
		b_index *= 2;
		flagset++;
	}
	return (flags);
}

int	ft_is_flagged(int flags, char *flagset, char f)
{
	int	comp;

	comp = 1;
	while (*flagset++ != f)
		comp *= 2;
	return ((flags & comp) != 0);
}
