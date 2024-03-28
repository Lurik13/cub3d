/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:52:49 by lribette          #+#    #+#             */
/*   Updated: 2024/03/28 09:53:44 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_char(char c)
{
	if (c == '.')
		printf(DOT_MSG);
	if (c == '0')
		printf(ZERO_MSG);
	if (c == '1')
		printf(ONE_MSG);
	if (c == ' ')
		printf(SPACE_MSG);
	if (c == 'n')
		printf(N_MSG);
	if (c == 's')
		printf(S_MSG);
	if (c == 'e')
		printf(E_MSG);
	if (c == 'w')
		printf(W_MSG);
	if (c == 'o')
		printf(O_MSG);
	if (c == 'c')
		printf(C_MSG);
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			print_char(map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
