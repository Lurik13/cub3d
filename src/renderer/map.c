/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 07:46:17 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/18 13:25:06 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static const int	g_colors[256] = {\
	['1'] = 0b00000000011110000001111000000000, \
	['0'] = 0b00000000000000000111100001111000, \
	['.'] = 0b00000000000111100110010000000000 //, \
	// ['c'] = 0b00000001111111111111111111111111
};

void	display_square(t_game *game, int colour, int i, int j)
{
	int	k;
	int	l;

	k = 0;
	while (k < SCALE_FACTOR)
	{
		l = 0;
		while (l < SCALE_FACTOR)
		{
			mlx_pixel_put \
			(
				game->texture->mlx, \
				game->texture->window, \
				i * SCALE_FACTOR + k, \
				j * SCALE_FACTOR + l, \
				colour \
			);
			l++;
		}
		k++;
	}
}

void	display_player(t_game *game)
{
	int	k;
	int	l;

	k = 0;
	while (k < PLAYER_SIZE)
	{
		l = 0;
		while (l < PLAYER_SIZE)
		{
			mlx_pixel_put(
				game->texture->mlx, \
				game->texture->window, \
				game->player->position->v * SCALE_FACTOR + k, \
				game->player->position->h * SCALE_FACTOR + l, \
				ft_color(230, 200, 0) \
			);
			l++;
		}
		k++;
	}
}

void	display_player_orientation(t_game *game)
{
	(void) game;
	// for (int i = 0; i < WIDTH; i++)
	// {
		send_ray(game, (1), ft_color(255, 0, 0));
		send_ray(game, (0), ft_color(0, 255, 255));
		send_ray(game, (-1), ft_color(255, 0, 0));
	// }
	// send_ray(game, 1 / (double)WIDTH - 1, ft_color(0, 0, 255));
	// send_ray(game, WIDTH / (double)WIDTH - 1, ft_color(0, 0, 255));
	// send_ray(game, (2 * 1279) / (double)WIDTH - 1, ft_color(255, 0, 0));
}

// Le if sur le caractere n permet d'eviter l'effet limace
void	display_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i <= game->longest_line)
	{
		j = 0;
		while (j < ft_tablen(game->map))
		{
			display_square(game, g_colors[(int)game->map[j][i]], i, j);
			display_player(game);
			j++;
		}
		i++;
	}
	display_player_orientation(game);
}
