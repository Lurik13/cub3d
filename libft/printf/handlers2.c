/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hrs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:14:57 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 07:06:15 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*h_pointer(va_list args)
{
	unsigned long long	ptr;
	char				*temp;
	char				*val;

	ptr = va_arg(args, unsigned long long);
	if (ptr == 0)
		return (ft_strdup("(nil)"));
	temp = ft_ultoa_base(ptr, HEX_BASE_MIN);
	val = ft_strjoin("0x", temp, NULL);
	free(temp);
	return (val);
}

char	*h_hex_min(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_uitoa_base(nb, HEX_BASE_MIN));
}

char	*h_hex_maj(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_uitoa_base(nb, HEX_BASE_MAJ));
}

char	*h_char(va_list args)
{
	char	*s;
	char	c;

	c = va_arg(args, int);
	s = ft_calloc(2, sizeof(char));
	s[0] = c;
	return (s);
}

char	*h_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}
