/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/18 09:31:53 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3d.h"
#include "vector/vector.h"

void	get_ray_direction(double ray[2], t_2dvector camera, t_2dvector fov,
		double cameraX)
{
	ray[DIRX] = camera.h + fov.h * cameraX;
	ray[DIRY] = camera.v + fov.v * cameraX;
}

void	get_ray_dist_per_step(double ray_dist[2], double ray[2])
{
	// printf("%'.2lf; %'.2lf\n", ray[DIRX], ray[DIRY]);
	if (ray[DIRX] > 0)
		ray_dist[DIRX] = ft_abs(1 / ray[DIRX]) / 10;
	else if (ray[DIRX] < 0)
		ray_dist[DIRX] = (1 - ft_abs(1 / ray[DIRX])) / 10;
	else
		ray_dist[DIRX] = 0;
	if (ray[DIRY] > 0)
		ray_dist[DIRY] = ft_abs(1 / ray[DIRY]) / 10;
	else if (ray[DIRY] < 0)
		ray_dist[DIRY] = (1 - ft_abs(1 / ray[DIRY])) / 10;
	else
		ray_dist[DIRY] = 0;
}

double	pythagoras(double ab, double bc)
{
	return (sqrt(ab * ab + bc * bc));
}

int	is_in_map(double coord[2], t_game *game)
{
	if (coord[DIRY] > ft_tablen(game->map))
		return (0);
	if (coord[DIRX] > game->longest_line)
		return (0);
	return (1);
}

void	send_ray(t_game *game, double start_position, int color)
{
	double		ray[2];
	double		*ray_pos;
	double		distance;
	double		ray_dist_per_step[2];
	t_2dvector	fov;

	ray_pos = (double []){game->player->position->v, game->player->position->h};
	fov = (t_2dvector){.h = 0.66f, .v = 0};
	get_ray_direction(ray, *game->player->camera, fov, start_position);
	get_ray_dist_per_step(ray_dist_per_step, ray);
	while (is_in_map(ray_pos, game) && \
		game->map[(int)ray_pos[DIRY]][(int)ray_pos[DIRX]] != '1')
	{
		mlx_pixel_put(game->texture->mlx, game->texture->window,
			ray_pos[DIRX] * SCALE_FACTOR, ray_pos[DIRY] * SCALE_FACTOR, color);
		ray_pos[DIRX] += ray_dist_per_step[DIRX];
		ray_pos[DIRY] += ray_dist_per_step[DIRY];
	}
	if ((int) game->player->position->h == (int) ray_pos[DIRY])
		ray_pos[DIRX] = (int)ray_pos[DIRX];
	else
		ray_pos[DIRY] = (int)ray_pos[DIRY];
	distance = pythagoras(
			ray_pos[DIRX] - game->player->position->v,
			ray_pos[DIRY] - game->player->position->h \
		);
}
// debug printf
	// printf("Player is at %'.2lf %'.2lf, the wall is at %'.2lf %'.2lf\n", 
	// 	game->player->position->v, game->player->position->h,
	// 	ray_pos[DIRX], ray_pos[DIRY]
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
	// game->player->camera->v = -1;
	// game->player->camera->h = 0;
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
