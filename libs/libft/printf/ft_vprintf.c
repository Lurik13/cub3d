/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:20:37 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/15 05:47:28 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include "../str/ft_str.h"
#include <stdarg.h>

int	ft_vsprintf(char *buf, const char *str, va_list lst)
{
	int		cpt;
	char	*chain;

	cpt = 0;
	buf[0] = '\0';
	while (*str)
	{
		if (*str != '%')
		{
			buf[cpt++] = *str++;
			buf[cpt] = '\0';
		}
		else if (*str == '%')
		{
			chain = format_str(&str, lst);
			cpt += ft_strlen(chain);
			ft_strlcat(buf, chain, cpt + ft_strlen(chain) + 1);
			free(chain);
		}
		str++;
	}
	return (cpt);
}

int	ft_vdprintf(int fd, const char *str, va_list lst)
{
	int		cpt;
	char	*chain;

	cpt = 0;
	while (*str)
	{
		if (*str != '%')
			cpt += write(1, str, 1);
		else if (*str == '%')
		{
			chain = format_str(&str, lst);
			cpt += write(fd, chain, ft_strlen(chain));
			free(chain);
		}
		str++;
	}
	return (cpt);
}
