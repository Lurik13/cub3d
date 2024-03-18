/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/18 07:45:12 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "vector/vector.h"

static const int	g_colors[256] = {\
	['1'] = 0b00000000011110000001111000000000, \
	['0'] = 0b00000000000000000111100001111000, \
	['.'] = 0b00000000000111100110010000000000
};

void	get_ray_direction(double ray[2], t_2dvector camera, t_2dvector fov,
		double cameraX)
{
	ray[DIRX] = camera.h + fov.v * cameraX;
	ray[DIRY] = camera.h + fov.h * cameraX;
}

void	get_ray_dist_per_step(double ray_dist[2], double ray[2])
{
	if (ray[DIRX] != 0)
		ray_dist[DIRX] = ft_abs(1 / ray[DIRX]);
	else
		ray_dist[DIRX] = ft_power(10, 30);
	if (ray[DIRY] != 0)
		ray_dist[DIRY] = ft_abs(1 / ray[DIRY]);
	else
		ray_dist[DIRY] = ft_power(10, 30);
}

double	pythagoras(double ab, double bc)
{
	return (sqrt(ab * ab + bc * bc));
}

double	get_distance_per_column(int column, t_game *game)
{
	double		ray[2];
	double		ray_pos[2];
	double		ray_dist_per_step[2];
	t_2dvector	fov;
	double		camerax;

	fov.h = 0;
	fov.v = 0.66f;
	camerax = 2 * column / (double)WIDTH - 1;
	ray_pos[DIRX] = game->player->position->h;
	ray_pos[DIRY] = game->player->position->v;
	get_ray_direction(ray, *game->player->camera, fov, camerax);
	get_ray_dist_per_step(ray_dist_per_step, ray);
	while (ray_pos[DIRX] < ft_tablen(game->map) && \
			ray_pos[DIRY] < game->longest_line && \
			game->map[(int)ray_pos[DIRX]][(int)ray_pos[DIRY]] != '1')
	{
		ray_pos[DIRX] += ray_dist_per_step[DIRX];
		ray_pos[DIRY] += ray_dist_per_step[DIRY];
	}
	if (ray_pos[DIRX] >= ft_tablen(game->map) || \
			ray_pos[DIRY] >= game->longest_line)
		return (0);
	return (pythagoras(ray_pos[DIRX] - game->player->position->h,
			ray_pos[DIRY] - game->player->position->v));
}

void	display_square(t_game *game, int colour, int i, int j)
{
	int	k;
	int	l;

	k = 0;
	while (k < SCALE_FACTOR)
	{
		l = 0;
		while (l < SCALE_FACTOR)
		{
			mlx_pixel_put \
			(
				game->texture->mlx, \
				game->texture->window, \
				i * SCALE_FACTOR + k, \
				j * SCALE_FACTOR + l, \
				colour \
			);
			l++;
		}
		k++;
	}
}

void	display_player(t_game *game)
{
	int	k;
	int	l;

	k = 0;
	while (k < PLAYER_SIZE)
	{
		l = 0;
		while (l < PLAYER_SIZE)
		{
			mlx_pixel_put(
				game->texture->mlx, \
				game->texture->window, \
				game->player->position->v * SCALE_FACTOR + k, \
				game->player->position->h * SCALE_FACTOR + l, \
				ft_color(230, 200, 0) \
			);
			l++;
		}
		k++;
	}
}

/**
 * @brief Propagate a ray until a wall is met.
 * @param `game` The game structure.
 * @param `start_position` The column of the screen from which the ray
 * should start.
 */
void	send_ray(t_game *game, int start_position)
{
	double		ray[2];
	double		*ray_pos;
	double		distance;
	double		ray_dist_per_step[2];
	t_2dvector	fov;

	ray_pos = (double []){game->player->position->v, game->player->position->h};
	fov = (t_2dvector){.h = 0.66f, .v = 0};
	get_ray_direction(ray, *game->player->camera, fov, start_position);
	ray_dist_per_step[DIRX] = 1;
	ray_dist_per_step[DIRY] = 0;
	while (game->map[(int)ray_pos[DIRY]][(int)ray_pos[DIRX]] != '1')
	{
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
// printf("Player is at %'.2lf %'.2lf, the wall is at %'.2lf %'.2lf\n", 
// 	game->player->position->v, game->player->position->h,
// 	ray_pos[DIRX], ray_pos[DIRY]
// );
// printf("The ray travelled %'.2lf\n", distance);

void	display_player_orientation(t_game *game)
{
	send_ray(game, WIDTH / 2);
}

// Le if sur le caractere n permet d'eviter l'effet limace
void	display_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i <= game->longest_line)
	{
		j = 0;
		while (j < ft_tablen(game->map))
		{
			if (game->map[j][i] == 'n')
				display_square(game, 0, i, j);
			display_square(game, g_colors[(int)game->map[j][i]], i, j);
			j++;
			display_player(game);
		}
		i++;
	}
	display_player_orientation(game);
}

void	render(void *param)
{
	void	*mlx;
	void	*window;
	t_game	*game;

	mlx = ((void **) param)[0];
	window = ((void **) param)[1];
	game = ((void **) param)[2];
	game->player->camera->v = -1;
	game->player->camera->h = 0;
	display_map(game);
}
// raycasting but it doesnt work
// double	ray_norm;
// for (int x = 0; x < WIDTH; x++)
// {
// 	ray_norm = get_distance_per_column(x, game);
// 	double	texture_height;
// 	if (ray_norm)
// 	{
// 		texture_height = (double)HEIGHT * (1 / ray_norm);
// 		for (int i = HEIGHT / 2 - texture_height / 2;
// 		i < HEIGHT / 2 + texture_height / 2; i++)
// 			mlx_pixel_put(mlx, window, x, i, ft_color(255, 0, 0));
// 	}
// }
