/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/19 07:28:57 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "vector/vector.h"

void	get_ray_direction(double ray[2], t_2dvector camera, t_2dvector fov,
		double cameraX)
{
	ray[H] = camera.h + fov.h * cameraX;
	ray[V] = camera.v + fov.v * cameraX;
	// printf("POS: {%'.2lf, %'.2lf}\n", ray[H], ray[V]);
}

void	get_ray_dist_per_step(double ray_dist[2], double ray[2])
{
	ray_dist[H] = ray[H] / 2;
	ray_dist[V] = ray[V] / 2;
}
	// printf("%'.2lf; %'.2lf\n", ray[H], ray[V]);

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
	double		ray_dir[2];
	double		*ray_pos;
	double		distance;
	double		ray_dist_per_step[2];
	t_2dvector	fov;

	ray_pos = (double []){game->player->position->h, game->player->position->v};
	fov = (t_2dvector){.h = 0.66f, .v = 0};
	get_ray_direction(ray_dir, *game->player->camera, fov, start_position);
	get_ray_dist_per_step(ray_dist_per_step, ray_dir);
	while (is_in_map(ray_pos, game) && \
		game->map[(int)ray_pos[V]][(int)ray_pos[H]] != '1')
	{
		mlx_pixel_put(game->texture->mlx, game->texture->window,
			ray_pos[H] * SCALE_FACTOR, ray_pos[V] * SCALE_FACTOR, color);
		ray_pos[V] += ray_dist_per_step[V];
		ray_pos[H] += ray_dist_per_step[H];
	}
	distance = ft_pythagoras(
			ray_pos[H] - game->player->position->v,
			ray_pos[V] - game->player->position->h \
		);
}
// debug printf
	// printf("Player is at %'.2lf %'.2lf, the wall is at %'.2lf %'.2lf\n", 
	// 	game->player->position->v, game->player->position->h,
	// 	ray_pos[H], ray_pos[V]
	// );
	// printf("The ray travelled %'.2lf\n", distance);
// end of debug printf

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
