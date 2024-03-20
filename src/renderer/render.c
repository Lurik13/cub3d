/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/20 12:49:30 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "vector/vector.h"

void	get_ray_direction(t_ray *ray, t_player player, double start_position);
void	get_ray_dist_per_step(t_ray *ray);
void	get_line_height(t_game *game, int col, t_ray ray);

void	render(void *param)
{
	void	*mlx;
	void	*window;
	t_game	*game;

	mlx = ((void **) param)[0];
	window = ((void **) param)[1];
	game = ((void **) param)[2];
	display_map(game);
}

// GET_RAY_DIR_AND_DIST
void	send_ray(t_game *game, double start_position, int color, int column)
{
	t_ray	ray;

	(void) color;
	ray.ray_start_pos[H] = game->player->position->h;
	ray.ray_start_pos[V] = game->player->position->v;
	// printf("Player coords : %f %f\n", game->player->position->h, game->player->position->v);
	ray.coords[H] = (int)ray.ray_start_pos[H];
	ray.coords[V] = (int)ray.ray_start_pos[V];
	get_ray_direction(&ray, *game->player, start_position);
	get_ray_dist_per_step(&ray);
	get_side_dists(&ray);
	search_for_a_wall(&ray, game);
	get_line_height(game, column, ray);
}

void	get_ray_direction(t_ray *ray, t_player player, double start_position)
{
	ray->ray_start_pos[H] = player.camera->h + player.fov.h * start_position;
	ray->ray_start_pos[V] = player.camera->v + player.fov.v * start_position;
}

void	get_ray_dist_per_step(t_ray *ray)
{
	if (ray->ray_start_pos[H] != 0)
		ray->ray_dist_per_step[H] = ft_abs(1 / ray->ray_start_pos[H]);
	else
		ray->ray_dist_per_step[H] = ft_power(10, 30);
	if (ray->ray_start_pos[V] != 0)
		ray->ray_dist_per_step[V] = ft_abs(1 / ray->ray_start_pos[V]);
	else
		ray->ray_dist_per_step[V] = ft_power(10, 30);
	// printf("%'.2lf %'.2lf\n", ray->ray_dist_per_step[H], ray->ray_dist_per_step[V]);
}

// GET_DDA_INFOS
void	get_side_dists(t_ray *ray)
{
	if (ray->ray_dir[H] < 0)
	{
		ray->step[H] = -1;
		ray->side_dist[H] = (ray->ray_start_pos[H] - ray->coords[H]) * ray->ray_dist_per_step[H];
	}
	else
	{
		ray->step[H] = 1;
		ray->side_dist[H] = (ray->coords[H] + 1.0 - ray->ray_start_pos[H]) * ray->ray_dist_per_step[H];
	}
	if (ray->ray_dir[V] < 0)
	{
		ray->step[V] = -1;
		ray->side_dist[V] = (ray->ray_start_pos[V] - ray->coords[V]) * ray->ray_dist_per_step[V];
	}
	else
	{
		ray->step[V] = 1;
		ray->side_dist[V] = (ray->coords[V] + 1.0 - ray->ray_start_pos[V]) * ray->ray_dist_per_step[V];
	}
}

// void	display_ray(double	coords[2], double start_coords[2], int color, t_game *game)
// {
	// double	step[2];

	// if (coords[H] > start_coords[H])
	// 	step[H] = (coords[H] - start_coords[H]) / 100;
	// else
	// 	step[H] = (start_coords[H] - coords[H]) / 100;
	// if (coords[V] > start_coords[V])
	// 	step[V] = (coords[V] - start_coords[V]) / 100;
	// else
	// 	step[V] = (start_coords[V] - coords[V]) / 100;
	// while (coords[V] > start_coords[V])
	// {
	// 	while (coords[H] < start_coords[H])
	// 	{
	// 		printf("%'.2lf %'.2lf\n", coords[H], coords[V]);
	// 		mlx_pixel_put(\
	// 			game->texture->mlx, \
	// 			game->texture->window, \
	// 			coords[V] * SCALE_FACTOR, \
	// 			coords[H] * SCALE_FACTOR, \
	// 			color);
	// 		coords[H] += step[H];
	// 	}
	// 	coords[V] -= step[V];
	// }
// }


void	search_for_a_wall(t_ray *ray, t_game *game)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist[H] < ray->side_dist[V]) {
			ray->side_dist[H] += ray->ray_dist_per_step[H];
			ray->coords[H] += ray->step[H];
			ray->side = 0;
		}
		else
		{
			ray->side_dist[V] += ray->ray_dist_per_step[V];
			ray->coords[V] += ray->step[V];
			ray->side = 1;
		}
		if (game->map[ray->coords[V]][ray->coords[H]] == '1')
			hit = 1;
	}
	if (ray->side == 0)
		ray->distance = ray->side_dist[H] - ray->ray_dist_per_step[H];
	else
		ray->distance = ray->side_dist[V] - ray->ray_dist_per_step[V];
}

void	get_line_height(t_game *game, int col, t_ray ray)
{
	int	line_height;
	int	color;
	int	line[2];

	line_height = (int) HEIGHT / ray.distance;
	line[0] = - line_height / 2 + HEIGHT / 2;
	if (line[0] < 0)
		line[0] = 0;
	line[1] = line_height / 2 + HEIGHT / 2;
	if (line[1] >= WIDTH)
		line[1] = HEIGHT - 1;
	for (int l = line[0]; l < line[1]; l++)
	{
		// printf("from %d to %d\n", line[0], line[1]);
		color = ft_color(255, 127, 125);
		if (ray.side == 0)
			color = color / 2;
		mlx_pixel_put(game->texture->mlx, game->texture->window, col, l, color);
	}
}

int	is_in_map(double coord[2], t_game *game)
{
	if (coord[V] > ft_tablen(game->map) - 1 || coord[V] < 0)
		return (0);
	if (coord[H] > game->longest_line - 1 || coord[H] < 0)
		return (0);
	return (1);
}
