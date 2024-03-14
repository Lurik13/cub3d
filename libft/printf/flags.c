/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 07:27:52 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 07:51:48 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_flags	parse_flags(const char **str)
{
	t_flags	flags;

	flags.padding = ft_atoi(*str);
	while (ft_isdigit(**str))
		*str += 1;
	return (flags);
}

char	*add_padding(char *str, t_flags flags)
{
	char	*newstr;

	if (flags.padding == 0 || ft_strlen(str) > (size_t) ft_abs(flags.padding))
	{
		return (str);
	}
	newstr = ft_calloc(flags.padding + 1, sizeof(char));
	ft_memset(newstr, ' ', flags.padding);
	if (flags.padding > 0)
		ft_memcpy(newstr, str, ft_strlen(str));
	else
		ft_memcpy(newstr + flags.padding - ft_strlen(str), str, ft_strlen(str));
	free(str);
	return (newstr);
}
