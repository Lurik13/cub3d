/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginning_orientation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:54:48 by lribette          #+#    #+#             */
/*   Updated: 2024/03/31 15:02:57 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate(t_player *player, double orientation)
{
	t_2dvector	old_fov;
	t_2dvector	old_camera;

	old_fov.h = player->fov.h;
	old_fov.v = player->fov.v;
	old_camera.h = player->camera->h;
	old_camera.v = player->camera->v;
	player->camera->h = old_camera.h * cos(orientation * ROTATION_SPEED)
		- player->camera->v * sin(orientation * ROTATION_SPEED);
	player->camera->v = old_camera.h * sin(orientation * ROTATION_SPEED)
		+ player->camera->v * cos(orientation * ROTATION_SPEED);
	player->fov.h = old_fov.h * cos(orientation * ROTATION_SPEED)
		- player->fov.v * sin(orientation * ROTATION_SPEED);
	player->fov.v = old_fov.h * sin(orientation * ROTATION_SPEED)
		+ player->fov.v * cos(orientation * ROTATION_SPEED);
}

void	choose_orientation(t_player *player, char c)
{
	player->camera->v = -1;
	player->fov.h = 0.66;
	if (c == 'S')
		rotate(player, 32);
	else if (c == 'E')
		rotate(player, 16);
	else if (c == 'W')
		rotate(player, 48);
}
