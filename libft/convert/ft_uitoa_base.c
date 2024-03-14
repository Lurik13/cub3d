/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 05:58:36 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 07:05:12 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	uitoa(unsigned int nb, char *base, char tab[33])
{
	unsigned int	baselen;
	char			*t;

	baselen = ft_strlen(base);
	t = ft_strchr(tab, '\0');
	*t = base[nb % baselen];
	if (nb >= baselen)
		uitoa(nb / baselen, base, tab);
}

char	*ft_uitoa_base(unsigned int nb, char *base)
{
	char			tab[33];

	ft_bzero(tab, 33);
	uitoa(nb, base, tab);
	return (ft_strdup(tab));
}

static void	ultoa(unsigned long nb, char *base, char tab[33])
{
	unsigned long	baselen;
	char			*t;

	baselen = ft_strlen(base);
	t = ft_strchr(tab, '\0');
	*t = base[nb % baselen];
	if (nb >= baselen)
		ultoa(nb / baselen, base, tab);
}

char	*ft_ultoa_base(unsigned long nb, char *base)
{
	char			tab[33];

	ft_bzero(tab, 33);
	ultoa(nb, base, tab);
	return (ft_strdup(tab));
}
