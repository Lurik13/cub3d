/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 07:46:17 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/25 11:20:52 by atu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static const int	g_colors[256] = {\
	['1'] = 0b00000001011110000001111000000000, \
	['0'] = 0b00000001000000000111100001111000, \
	['.'] = 0b00000001000111100110010000000000 /*, \
	['c'] = 0b00000001111111111111111111111111*/
};

void	display_square(t_game *game, int colour, int h_start, int v_start)
{
	int	h;
	int	v;

	h = 0;
	while (h < SCALE_FACTOR)
	{
		v = 0;
		while (v < SCALE_FACTOR)
		{
			my_mlx_pixel_put(
				game->texture->map, \
				h_start * SCALE_FACTOR + h, \
				v_start * SCALE_FACTOR + v, \
				colour);
			v++;
		}
		h++;
	}
}

void	display_player(t_game *game)
{
	int	h;
	int	v;

	h = 0;
	while (h < PLAYER_SIZE)
	{
		v = 0;
		while (v < PLAYER_SIZE)
		{
			my_mlx_pixel_put(\
				game->texture->map, \
				game->player->position->h * SCALE_FACTOR + h, \
				game->player->position->v * SCALE_FACTOR + v, \
				ft_color(230, 200, 0));
			v++;
		}
		h++;
	}
}

void	display_map(t_game *game)
{
	int	h;
	int	v;

	h = 0;
	while (h <= game->longest_line)
	{
		v = 0;
		while (v < ft_tablen(game->map))
		{
			display_square(game, g_colors[(int)game->map[v][h]], h, v);
			display_player(game);
			v++;
		}
		h++;
	}
}
