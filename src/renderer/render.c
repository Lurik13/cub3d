/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/22 06:56:22 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "vector/vector.h"
#include "controls.h"

void	render(void *param)
{
	void	*mlx;
	void	*window;
	t_game	*game;
	int		column;

	mlx = ((void **) param)[0];
	window = ((void **) param)[1];
	game = ((void **) param)[2];
	display_map(game);
	send_ray(game, (double)(-WIDTH) / (double)WIDTH,
		ft_color(255, 0, 0), 0);
	column = 1;
	while (column < WIDTH)
	{
		send_ray(\
			game, \
			(double)(column * 2 - WIDTH) / (double)WIDTH, \
			0, \
			column \
		);
		column++;
	}
	send_ray(game, (double)(column * 2 - WIDTH) / (double)WIDTH,
		ft_color(255, 0, 0), WIDTH);
}

void	send_ray(t_game *game, double start_position, int color, int column)
{
	t_ray	ray;

	(void) color;
	ray.ray_start_pos[H] = game->player->position->h + (MOVEMENT / 2);
	ray.ray_start_pos[V] = game->player->position->v + MOVEMENT;
	ray.coords[H] = (int)ray.ray_start_pos[H];
	ray.coords[V] = (int)ray.ray_start_pos[V];
	get_ray_direction(&ray, *game->player, start_position);
	get_ray_dist_per_step(&ray);
	get_side_dists(&ray);
	search_for_a_wall(&ray, game);
	get_line_height(game, column, &ray);
}

int	is_in_map(double coord[2], t_game *game)
{
	if (coord[V] > ft_tablen(game->map) - 1 || coord[V] < 0)
		return (0);
	if (coord[H] > game->longest_line - 1 || coord[H] < 0)
		return (0);
	return (1);
}

void	display_ray(t_ray ray, int color, t_game *game)
{
	double	step[2];

	if (ray.coords[H] > ray.ray_start_pos[H])
		step[H] = (ray.coords[H] - ray.ray_start_pos[H]) / 100;
	else
		step[H] = (ray.ray_start_pos[H] - ray.coords[H]) / 100;
	if (ray.coords[V] > ray.ray_start_pos[V])
		step[V] = (ray.coords[V] - ray.ray_start_pos[V]) / 100;
	else
		step[V] = (ray.ray_start_pos[V] - ray.coords[V]) / 100;
	while (ray.coords[V] > ray.ray_start_pos[V])
	{
		while (ray.coords[H] > ray.ray_start_pos[H])
		{
			mlx_pixel_put(\
				game->texture->mlx, \
				game->texture->window, \
				ray.coords[V] * SCALE_FACTOR, \
				ray.coords[H] * SCALE_FACTOR, \
				color);
			ray.coords[H] += step[H];
		}
		ray.coords[V] -= step[V];
	}
}

void	render_column(t_ray *ray, t_game *game, int col)
{
	int	color;
	int	l;

	l = 0;
	while (l < ray->line[0])
	{
		mlx_pixel_put(game->texture->mlx, game->texture->window, \
			col, l, ft_color(42, 42, 420 % 255));
		l++;
	}
	while (l < ray->line[1])
	{
		color = ft_color(60, 60, 60);
		if (ray->side == 1)
			color = ft_color(120, 120, 120);
		mlx_pixel_put(game->texture->mlx, game->texture->window, \
			col, l, color);
		l++;
	}
	while (l < HEIGHT)
	{
		mlx_pixel_put(game->texture->mlx, game->texture->window, \
			col, l, ft_color(420 % 255, 42, 42));
		l++;
	}
}
