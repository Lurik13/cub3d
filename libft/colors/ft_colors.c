/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 05:58:49 by aboyreau          #+#    #+#             */
/*   Updated: 2024/01/08 06:00:10 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_gradient(int color1, int color2, float step)
{
	int	r[2];
	int	g[2];
	int	b[2];
	int	finalcolor;

	step = step / 100;
	r[0] = color1 >> 16;
	g[0] = (color1 >> 8) % 0x100;
	b[0] = color1 % 0x100;
	r[1] = color2 >> 16;
	g[1] = (color2 >> 8) % 0x100;
	b[1] = color2 % 0x100;
	finalcolor = (r[0] + (step) * (r[1] - r[0]));
	finalcolor *= 0x100;
	finalcolor += (g[0] + (step) * (g[1] - g[0]));
	finalcolor *= 0x100;
	finalcolor += (b[0] + (step) * (b[1] - b[0]));
	return (finalcolor);
}
