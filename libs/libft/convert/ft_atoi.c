/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 01:01:57 by atu               #+#    #+#             */
/*   Updated: 2024/04/08 17:33:46 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int		neg;
	long	resultat;

	neg = 1;
	resultat = 0;
	while (*nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		resultat = resultat * 10 + *nptr - '0';
		nptr++;
	}
	while (*nptr == ' ')
		nptr++;
	if (*nptr != ',' && *nptr != '\0')
		return (256);
	return (neg * (int)resultat);
}
