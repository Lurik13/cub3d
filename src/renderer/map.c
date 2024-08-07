/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 07:46:17 by aboyreau          #+#    #+#             */
/*   Updated: 2024/04/07 08:50:57 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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
			my_mlx_pixel_put(game->texture->map, h_start * SCALE_FACTOR + h,
				v_start * SCALE_FACTOR + v, colour);
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
			my_mlx_pixel_put(game->texture->map, game->player->position->h
				* SCALE_FACTOR + h, game->player->position->v * SCALE_FACTOR
				+ v, ft_color(230, 200, 0));
			v++;
		}
		h++;
	}
}

void	display_map(t_game *game)
{
	static const int	g_colors[256] = {\
		['1'] = 0b00000000011110000001111000000000, \
		['0'] = 0b00000000000000000111100001111000, \
		['.'] = 0b00000000000111100110010000000000
	};
	int					h;
	int					v;

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

int	load_texture(t_game *game)
{
	int		i;
	int		exit_code;
	char	*path;

	i = 0;
	exit_code = 0;
	while (i < 4)
	{
		path = game->texture->wall[i];
		game->texture->wall[i] = ft_calloc(1, sizeof(t_text));
		((t_text **)game->texture->wall)[i]->texture = mlx_xpm_file_to_image(
				game->texture->mlx,
				path, &((t_text **)game->texture->wall)[i]->height,
				&((t_text **)game->texture->wall)[i]->width);
		if (((t_text **)game->texture->wall)[i]->texture == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Cannot load the texture %s\n", path);
			exit_code = 42;
		}
		free(path);
		i++;
	}
	return (exit_code);
}

void	display_game(t_game *game)
{
	int	column;

	column = 0;
	while (column < WIDTH)
	{
		send_ray(game, (double)(column * 2 - WIDTH) / (double)WIDTH, 0, column);
		column++;
	}
}
