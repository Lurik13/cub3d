/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:25:46 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/21 12:12:28 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "controls.h"
#include "render.h"
#include "vector/vector.h"

void	ft_move(t_game *game, double move_v, double move_h)
{
	t_player	*player;
	int			pos_v;
	int			pos_h;

	player = game->player;
	pos_v = (player->position->v + move_v);
	pos_h = (player->position->h + move_h);
	if (game->map[(int)(player->position->v + 2 * move_v)] \
		[(int)(player->position->h + 2 * move_h)] == '1' && \
		(move_v > 0 || move_h > 0))
		return ;
	if (ft_strcontains(" nsewo", game->map[pos_v][pos_h]))
	{
		game->map[(int)player->position->v][(int)player->position->h] = ' ';
		game->player->position->v += move_v;
		game->player->position->h += move_h;
		game->map[(int)player->position->v][(int)player->position->h] = 'n';
	}
}

#define ROTATION_SPEED 0.1
void	ft_rotate(t_game *game, int orientation)
{
	// game->player->fov.h -= movement;
	// game->player->fov.v += movement;
	// game->player->camera->h -= movement;
	// game->player->camera->v += movement;

	t_2dvector	old_fov;
	t_2dvector	old_camera;

	old_fov.h = game->player->fov.h;
	old_fov.v = game->player->fov.v;

	old_camera.h = game->player->camera->h;
	old_camera.v = game->player->camera->v;

	game->player->camera->h = old_camera.h * cos(orientation * ROTATION_SPEED) - game->player->camera->v * sin(orientation * ROTATION_SPEED);
	game->player->camera->v = old_camera.h * sin(orientation * ROTATION_SPEED) + game->player->camera->v * cos(orientation * ROTATION_SPEED);

	game->player->fov.h = old_fov.h * cos(orientation * ROTATION_SPEED) - game->player->fov.v * sin(orientation * ROTATION_SPEED);
	game->player->fov.v = old_fov.h * sin(orientation * ROTATION_SPEED) + game->player->fov.v * cos(orientation * ROTATION_SPEED);
}	

void	move(int keycode, t_game *game)
{
	double	movement;

	movement = MOVEMENT;
	if (keycode == LEFT_KEY)
		ft_move(game, 0, -movement);
	else if (keycode == RIGHT_KEY)
		ft_move(game, 0, +movement);
	else if (keycode == DOWN_KEY)
		ft_move(game, +movement, 0);
	else if (keycode == UP_KEY)
		ft_move(game, -movement, 0);
	else if (keycode == 65361)
		ft_rotate(game, -1);
	else if (keycode == 65363)
		ft_rotate(game, 1);
}
	// printf("%d\n", keycode);
	// 	else if (keycode == 65364)
	// 		look_left(game);
	// 	else if (keycode == 65365)
	// 		look_right(game);
