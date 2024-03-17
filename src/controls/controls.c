/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:25:46 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/17 10:16:53 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "controls.h"

void	to_right(t_game *game)
{
	t_player *player;

	player = game->player;
	game->map[(int)player->position->h][(int)player->position->v] = ' ';
	game->player->position->v += 0.5;
	game->map[(int)player->position->h][(int)player->position->v] = 'n';
	printf("Position : %d, %d\n", (int)player->position->v, (int)player->position->h);
}

void	to_up(t_game *game)
{
	t_player *player;

	player = game->player;
	game->map[(int)player->position->h][(int)player->position->v] = ' ';
	game->player->position->h += 0.5;
	game->map[(int)player->position->h][(int)player->position->v] = 'n';
}

void	to_down(t_game *game)
{
	t_player *player;

	player = game->player;
	game->map[(int)player->position->h][(int)player->position->v] = ' ';
	game->player->position->h -= 0.5;
	game->map[(int)player->position->h][(int)player->position->v] = 'n';
}

void	to_left(t_game *game)
{
	t_player *player;

	player = game->player;
	game->map[(int)player->position->h][(int)player->position->v] = ' ';
	game->player->position->v -= 0.5;
	game->map[(int)player->position->h][(int)player->position->v] = 'n';
}

void	move(int keycode, t_game *game)
{
	printf("KEYCODE : %d\n", keycode);
	if (keycode == 97)
		to_left(game);
	else if (keycode == 115)
		to_up(game);
	else if (keycode == 100)
		to_right(game);
	else if (keycode == 119)
		to_down(game);	
}