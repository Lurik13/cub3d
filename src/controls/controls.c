/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:25:46 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/17 11:17:24 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "controls.h"

const static double MOVEMENT = (double)((double)6 / (double)24);

void	to_right(t_game *game)
{
	t_player *player;

	player = game->player;
	printf("Coords : %lf, %lf\n", player->position->h, player->position->v);
	if (ft_strcontains(" no", game->map[(int)player->position->h][(int)(player->position->v + MOVEMENT)]))
	{
		game->map[(int)player->position->h][(int)player->position->v] = ' ';
		game->player->position->v += MOVEMENT;
		game->map[(int)player->position->h][(int)player->position->v] = 'n';
	}
}

void	to_down(t_game *game)
{
	t_player *player;

	player = game->player;
	if (ft_strcontains(" no", game->map[(int)(player->position->h + MOVEMENT)][(int)player->position->v]))
	{
		game->map[(int)player->position->h][(int)player->position->v] = ' ';
		game->player->position->h += MOVEMENT;
		game->map[(int)player->position->h][(int)player->position->v] = 'n';
	}
}

void	to_up(t_game *game)
{
	t_player *player;

	player = game->player;
	player = game->player;
	if (ft_strcontains(" no", game->map[(int)(player->position->h - MOVEMENT)][(int)player->position->v]))
	{
		game->map[(int)player->position->h][(int)player->position->v] = ' ';
		game->player->position->h -= MOVEMENT;
		game->map[(int)player->position->h][(int)player->position->v] = 'n';
	}
}

void	to_left(t_game *game)
{
	t_player *player;

	player = game->player;
	if (ft_strcontains(" no", game->map[(int)player->position->h][(int)(player->position->v - MOVEMENT)]))
	{
		game->map[(int)player->position->h][(int)player->position->v] = ' ';
		game->player->position->v -= MOVEMENT;
		game->map[(int)player->position->h][(int)player->position->v] = 'n';
	}
}

void	move(int keycode, t_game *game)
{
	printf("%d\n", keycode);
	if (keycode == 97)
		to_left(game);
	else if (keycode == 119)
		to_up(game);
	else if (keycode == 100)
		to_right(game);
	else if (keycode == 115)
		to_down(game);
// 	else if (keycode == 65364)
// 		look_left(game);
// 	else if (keycode == 65365)
// 		look_right(game);
}
