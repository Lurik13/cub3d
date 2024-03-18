/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:25:46 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/18 18:55:58 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "controls.h"

void	ft_move(t_game *game, double move_v, double move_h)
{
	t_player *player;

	player = game->player;
	if (ft_strcontains(" no", game->map[(int)(player->position->v + move_v)][(int)(player->position->h + move_h)]))
	{
		game->map[(int)player->position->v][(int)player->position->h] = ' ';
		game->player->position->v += move_v;
		game->player->position->h += move_h;
		game->map[(int)player->position->v][(int)player->position->h] = 'n';
	}
}

void	move(int keycode, t_game *game)
{
	double	movement;

	movement = 0.25;
	// printf("%d\n", keycode);
	if (keycode == LEFT_KEY)
		ft_move(game, 0, - movement);
	else if (keycode == RIGHT_KEY)
		ft_move(game, 0, + movement);
	else if (keycode == DOWN_KEY)
		ft_move(game, + movement, 0);
	else if (keycode == UP_KEY)
		ft_move(game, - movement, 0);
// 	else if (keycode == 65364)
// 		look_left(game);
// 	else if (keycode == 65365)
// 		look_right(game);
}
