/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:20:37 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 08:14:48 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
#include "../str/ft_str.h"
#include <stdarg.h>

char	*format_str(const char **str, va_list lst)
{
	t_flags		flags;
	char		*chain;
	static char	*(*handlers[256])(va_list) = {\
		['c'] = h_char, ['s'] = h_string, \
		['x'] = h_hex_min, ['X'] = h_hex_maj, ['u'] = h_uint, \
		['p'] = h_pointer, ['d'] = h_int, ['i'] = h_int, ['%'] = h_percent \
	};

	(*str)++;
	flags = parse_flags(str);
	if (handlers[(unsigned char) **str] == NULL)
		return (NULL);
	chain = handlers[(unsigned char) **str](lst);
	if (chain == NULL)
		return (NULL);
	chain = add_padding(chain, flags);
	return (chain);
}

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

int	ft_sprintf(char *buf, const char *str, ...)
{
	va_list		lst;
	int			cpt;

	cpt = 0;
	va_start(lst, str);
	cpt = ft_vsprintf(buf, str, lst);
	va_end(lst);
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

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list		lst;
	int			cpt;

	cpt = 0;
	va_start(lst, str);
	cpt = ft_vdprintf(fd, str, lst);
	va_end(lst);
	return (cpt);
}

int	ft_printf(const char *str, ...)
{
	va_list		lst;
	int			cpt;

	cpt = 0;
	va_start(lst, str);
	cpt = ft_vdprintf(1, str, lst);
	return (cpt);
}
