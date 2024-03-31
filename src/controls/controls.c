/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:25:46 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/31 15:26:27 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "cub3d.h"
#include "render.h"
#include "vector/vector.h"

void	ft_move_player_in_struct(t_game *game, t_player *player, \
	double pos_v, double pos_h)
{
	if (ft_strcontains(" nsewo", game->map[(int)pos_v][(int)pos_h]))
	{
		game->map[(int)player->position->v][(int)player->position->h] = ' ';
		game->player->position->v = pos_v;
		game->player->position->h = pos_h;
		game->map[(int)player->position->v][(int)player->position->h] = 'n';
	}
}

void	ft_move(t_game *game, double move, int side)
{
	t_player	*player;
	double		pos_v;
	double		pos_h;

	player = game->player;
	if (side)
	{
		pos_h = player->position->h - player->camera->v * move;
		pos_v = player->position->v + player->camera->h * move;
	}
	else
	{
		pos_h = player->position->h + player->camera->h * move;
		pos_v = player->position->v + player->camera->v * move;
	}
	if (verif_wall(game->map, move, pos_v, pos_h) == EXIT_SUCCESS)
		ft_move_player_in_struct(game, player, pos_v, pos_h);
}

void	ft_rotate(t_game *game, double orientation)
{
	t_2dvector	old_fov;
	t_2dvector	old_camera;

	old_fov.h = game->player->fov.h;
	old_fov.v = game->player->fov.v;
	old_camera.h = game->player->camera->h;
	old_camera.v = game->player->camera->v;
	game->player->camera->h = old_camera.h * cos(orientation * ROTATION_SPEED)
		- game->player->camera->v * sin(orientation * ROTATION_SPEED);
	game->player->camera->v = old_camera.h * sin(orientation * ROTATION_SPEED)
		+ game->player->camera->v * cos(orientation * ROTATION_SPEED);
	game->player->fov.h = old_fov.h * cos(orientation * ROTATION_SPEED)
		- game->player->fov.v * sin(orientation * ROTATION_SPEED);
	game->player->fov.v = old_fov.h * sin(orientation * ROTATION_SPEED)
		+ game->player->fov.v * cos(orientation * ROTATION_SPEED);
}

void	mouse_rotate(int x, int y, void *param)
{
	static int	h = 0;
	t_game		*game;
	int			*redraw;

	(void)y;
	game = ((t_game **)param)[0];
	redraw = ((int **)param)[3];
	if (h == WIDTH - 1)
		h = WIDTH - 2;
	if (h > x)
		ft_rotate(game, -0.3);
	else if (h < x)
		ft_rotate(game, 0.3);
	h = x;
	if (h == 0)
		h = 1;
	*redraw = 1;
}

void	move(int keycode, void *data)
{
	t_game	*game;
	int		*redraw;

	game = ((t_game **)data)[0];
	redraw = ((int **)data)[3];
	if (keycode == LEFT_KEY)
		ft_move(game, -MOVEMENT, 1);
	else if (keycode == RIGHT_KEY)
		ft_move(game, MOVEMENT, 1);
	else if (keycode == DOWN_KEY)
		ft_move(game, -MOVEMENT, 0);
	else if (keycode == UP_KEY)
		ft_move(game, MOVEMENT, 0);
	else if (keycode == LEFT_ARROW_KEY)
		ft_rotate(game, -1);
	else if (keycode == RIGHT_ARROW_KEY)
		ft_rotate(game, 1);
	else if (keycode == ESCAPE_KEY)
		mlx_close(ESCAPE_KEY, game->texture->mlx);
	*redraw = 1;
}
