/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:25:46 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/23 10:14:43 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "cub3d.h"
#include "render.h"
#include "vector/vector.h"

void	ft_move_forward_backward(t_game *game, double move_h)
{
	t_player	*player;
	double		pos_v;
	double		pos_h;

	player = game->player;
	pos_h = (player->position->h + player->camera->h * move_h);
	pos_v = (player->position->v + player->camera->v * move_h);
	if (game->map[(int)(pos_v + player->camera->v * move_h)]
			[(int)(pos_h + (player->camera->h * move_h))] == '1')
		return ;
	if (ft_strcontains(" nsewo", game->map[(int)pos_v][(int)pos_h]))
	{
		game->map[(int)player->position->v][(int)player->position->h] = ' ';
		game->player->position->v = pos_v;
		game->player->position->h = pos_h;
		game->map[(int)player->position->v][(int)player->position->h] = 'n';
	}
}

void	ft_move_sides(t_game *game, double move_h)
{
	t_player	*player;
	double		pos_v;
	double		pos_h;

	player = game->player;
	pos_h = player->position->h - (player->camera->v * move_h);
	pos_v = player->position->v + (player->camera->h * move_h);
	if (game->map[(int)(pos_v + player->camera->h * move_h)][(int)(pos_h
			+ player->camera->v * move_h)] == '1')
		return ;
	if (ft_strcontains(" nsewo", game->map[(int)pos_v][(int)pos_h]))
	{
		game->map[(int)player->position->v][(int)player->position->h] = ' ';
		game->player->position->v = pos_v;
		game->player->position->h = pos_h;
		game->map[(int)player->position->v][(int)player->position->h] = 'n';
	}
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
	void		*mlx;
	void		*window;
	int			*redraw;

	(void)y;
	game = ((t_game **)param)[0];
	mlx = ((void **)param)[1];
	window = ((void **)param)[2];
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

#define ESCAPE_KEY 65307

void	move(int keycode, void *data)
{
	double	movement;
	t_game	*game;
	int		*redraw;

	game = ((t_game **)data)[0];
	redraw = ((int **)data)[3];
	movement = MOVEMENT;
	if (keycode == LEFT_KEY)
		ft_move_sides(game, -movement);
	else if (keycode == RIGHT_KEY)
		ft_move_sides(game, movement);
	else if (keycode == DOWN_KEY)
		ft_move_forward_backward(game, -movement);
	else if (keycode == UP_KEY)
		ft_move_forward_backward(game, movement);
	else if (keycode == 65361)
		ft_rotate(game, -1);
	else if (keycode == 65363)
		ft_rotate(game, 1);
	else if (keycode == ESCAPE_KEY)
		mlx_close(ESCAPE_KEY, game->texture->mlx);
	*redraw = 1;
}
