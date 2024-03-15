/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 00:13:29 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 07:59:36 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*h_int(va_list args)
{
	int		nb;

	nb = va_arg(args, int);
	return (ft_itoa(nb));
}

char	*h_uint(va_list args)
{
	unsigned int		nb;

	nb = va_arg(args, unsigned int);
	return (ft_uitoa(nb));
}

char	*h_percent(__attribute__((unused)) va_list arg)
{
	return (ft_strdup("%"));
}

char	*h_void(__attribute__((unused)) va_list arg)
{
	return (NULL);
}
