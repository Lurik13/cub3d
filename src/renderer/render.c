/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/19 12:42:14 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "vector/vector.h"

void	get_ray_direction(double ray[2], t_2dvector camera, t_2dvector fov,
		double start_position)
{
	ray[H] = camera.h + fov.h * start_position;
	ray[V] = camera.v + fov.v * start_position;
}

void	get_ray_dist_per_step(double ray_dist[2], double ray[2])
{
	if (ray[H] != 0)
		ray_dist[H] = ft_abs(1 /ray[H]);
	else
		ray_dist[H] = ft_power(10, 30);
	if (ray[V] != 0)
		ray_dist[V] = ft_abs(1 / ray[V]);
	else
		ray_dist[V] = ft_power(10, 30);
}

int	is_in_map(double coord[2], t_game *game)
{
	if (coord[V] > ft_tablen(game->map) - 1 || coord[V] < 0)
		return (0);
	if (coord[H] > game->longest_line - 1 || coord[H] < 0)
		return (0);
	return (1);
}

void	send_ray(t_game *game, double start_position, int color)
{
	// GET_RAY_DIR_AND_DIST
	double		ray_dir[2];
	double		*ray_pos;
	double		distance;
	double		ray_dist_per_step[2];
	t_2dvector	fov;

	ray_pos = (double []){game->player->position->h, game->player->position->v};
	fov = (t_2dvector){.h = 0.66, .v = 0.66};
	get_ray_direction(ray_dir, *game->player->camera, fov, start_position);
	get_ray_dist_per_step(ray_dist_per_step, ray_dir);


	//
	int map_h = (int)(ray_pos[H]);
	int map_v = (int)(ray_pos[V]);
	//
	// GET_DDA_INFOS
	int step_h;
	int step_v;
	int side_dist_h;
	int side_dist_v;
	if (ray_dir[H] < 0)
	{
		step_h = -1;
		side_dist_h = (ray_pos[H] - map_h) * ray_dist_per_step[H];
	}
	else
	{
		step_h = 1;
		side_dist_h = (map_h + 1.0 - ray_pos[H]) * ray_dist_per_step[H];
	}
	if (ray_dir[V] < 0)
	{
		step_v = -1;
		side_dist_v = (ray_pos[V] - map_v) * ray_dist_per_step[V];
	}
	else
	{
		step_v = 1;
		side_dist_v = (map_v + 1.0 - ray_pos[V]) * ray_dist_per_step[V];
	}


	int	side;
	int	hit = 0;
	// DDA
	while (hit == 0)
	{
		// display_square(game, color, map_h, map_v);
		if (side_dist_h < side_dist_v)
		{
			side_dist_h += ray_dist_per_step[H];
			map_h += step_h;
			side = 0;
		}
		else
		{
			side_dist_v += ray_dist_per_step[V];
			map_v += step_v;
			side = 1;
		}
		if (game->map[map_v][map_h] == '1')
			hit = 1;
		for (float i = map_h; i < map_h + 1; i += 0.1)
		{
			for (float j = map_v; j < map_v + 1; j += 0.1)
			{
				mlx_pixel_put(\
					game->texture->mlx, \
					game->texture->window, \
					i * SCALE_FACTOR, \
					j * SCALE_FACTOR, \
					color);
			}
		}
	}
	if (side == 0)
		distance = side_dist_h - ray_dist_per_step[H];
	else
		distance = side_dist_v - ray_dist_per_step[V];

	// for (double j = map_h; (int)j != (int)ray_pos[H]; j += ft_abs(ray_pos[H] - map_h) / 100000000000)
	// {
	// 	for (double i = ray_pos[V]; (int)i != (int)map_v; i += ft_abs(ray_pos[V] - map_v) / 100000000000)
	// 	{
	// 		mlx_pixel_put(game->texture->mlx, 
	// 				game->texture->window, 
	// 				j * SCALE_FACTOR,
	// 				i * SCALE_FACTOR, 
	// 				ft_color(255, 255, 255));
	// 	}
	// }
	// printf("%lf\n", distance);
}

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
// raycasting but it doesnt work
	//double	ray_norm;
	//for (int x = 0; x < WIDTH; x++)
	//{
	//	ray_norm = get_distance_per_column(x, game);
	//	double	texture_height;
	//	if (ray_norm)
	//	{
	//		texture_height = (double)HEIGHT * (1 / ray_norm);
	//		for (int i = HEIGHT / 2 - texture_height / 2;
	//		i < HEIGHT / 2 + texture_height / 2; i++)
	//			mlx_pixel_put(mlx, window, x, i, ft_color(255, 0, 0));
	//	}
	//}
// end of raycasting
