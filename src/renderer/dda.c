/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 06:32:29 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/28 12:17:23 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	get_ray_direction(t_ray *ray, t_player player, double start_position)
{
	ray->ray_dir[H] = player.camera->h + player.fov.h * start_position;
	ray->ray_dir[V] = player.camera->v + player.fov.v * start_position;
}

void	get_ray_dist_per_step(t_ray *ray)
{
	if (ray->ray_dir[H] != 0)
		ray->ray_dist_per_step[H] = ft_abs(1 / ray->ray_dir[H]);
	else
		ray->ray_dist_per_step[H] = 1e30;
	if (ray->ray_dir[V] != 0)
		ray->ray_dist_per_step[V] = ft_abs(1 / ray->ray_dir[V]);
	else
		ray->ray_dist_per_step[V] = 1e30;
}

void	get_side_dists(t_ray *ray)
{
	if (ray->ray_dir[H] < 0)
	{
		ray->step[H] = -1;
		ray->side_dist[H] = (ray->ray_start_pos[H] - ray->coords[H])
			* ray->ray_dist_per_step[H];
	}
	else
	{
		ray->step[H] = 1;
		ray->side_dist[H] = (ray->coords[H] + 1.0 - ray->ray_start_pos[H])
			* ray->ray_dist_per_step[H];
	}
	if (ray->ray_dir[V] < 0)
	{
		ray->step[V] = -1;
		ray->side_dist[V] = (ray->ray_start_pos[V] - ray->coords[V])
			* ray->ray_dist_per_step[V];
	}
	else
	{
		ray->step[V] = 1;
		ray->side_dist[V] = (ray->coords[V] + 1.0 - ray->ray_start_pos[V])
			* ray->ray_dist_per_step[V];
	}
}

void	search_for_a_wall(t_ray *ray, t_game *game)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist[H] < ray->side_dist[V])
		{
			ray->side_dist[H] += ray->ray_dist_per_step[H];
			ray->coords[H] += ray->step[H];
			ray->side = 0;
			if (ray->step[H] > 0)
				ray->texture_index = EAST;
			else
				ray->texture_index = WEST;
		}
		else
		{
			ray->side_dist[V] += ray->ray_dist_per_step[V];
			ray->coords[V] += ray->step[V];
			ray->side = 1;
			if (ray->step[V] > 0)
				ray->texture_index = SOUTH;
			else
				ray->texture_index = NORTH;
		}
		if (ray->coords[V] >= ft_tablen(game->map) || ray->coords[V] >= game->\
			longest_line || game->map[ray->coords[V]][ray->coords[H]] == '1')
			hit = 1;
	}
	if (ray->side == 0)
		ray->distance = ray->side_dist[H] - ray->ray_dist_per_step[H];
	else
		ray->distance = ray->side_dist[V] - ray->ray_dist_per_step[V];
}

void	get_line_height(t_game *game, int col, t_ray *ray)
{
	int	line_height;

	line_height = (int)(HEIGHT / ray->distance);
	ray->line[0] = (-line_height / 2) + (HEIGHT / 2);
	if (ray->line[0] < 0)
		ray->line[0] = 0;
	ray->line[1] = (line_height / 2) + (HEIGHT / 2);
	if (ray->line[1] >= HEIGHT)
		ray->line[1] = HEIGHT - 1;
	render_textured_column(ray, game, col);
}
