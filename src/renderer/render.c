/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/17 10:26:13 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../libft/math/math.h"
#include "cub3d.h"
#include "vector/vector.h"
#include <float.h>
#include <math.h>

#define DIRX 0
#define DIRY 1

void	get_ray_direction(double	ray[2], t_2dvector camera, t_2dvector fov,
		double cameraX)
{
	ray[DIRX] = camera.h + fov.v * cameraX;
	ray[DIRY] = camera.h + fov.h * cameraX;
}

void	get_ray_dist_per_step(double ray_dist[2], double	ray[2])
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
	double		cameraX;

	fov.h = 0;
	fov.v = 0.66f;
	cameraX = 2 * column / (double)WIDTH - 1;
	ray_pos[DIRX] = game->player->position->h;
	ray_pos[DIRY] = game->player->position->v;
	get_ray_direction(ray, *game->player->camera, fov, cameraX);
	get_ray_dist_per_step(ray_dist_per_step, ray);
	while (ray_pos[DIRX] < ft_tablen(game->map) &&
			ray_pos[DIRY] < game->longest_line && 
			game->map[(int)ray_pos[DIRX]][(int)ray_pos[DIRY]] != '1')
	{
		ray_pos[DIRX] += ray_dist_per_step[DIRX];
		ray_pos[DIRY] += ray_dist_per_step[DIRY];
	}
	if (ray_pos[DIRX] >= ft_tablen(game->map) ||
			ray_pos[DIRY] >= game->longest_line)
		return (0);
	return (pythagoras(ray_pos[DIRX] - game->player->position->h,
			ray_pos[DIRY] - game->player->position->v));
}

# define SCALE_FACTOR 10
# define PLAYER_SIZE 5
void	display_map(void *mlx, void *window, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i <= game->longest_line)
	{
		j = 0;
		while (j < ft_tablen(game->map))
		{
			if (game->map[j][i] == ' ' || game->map[j][i] == 'n')
				for (int k = 0; k < SCALE_FACTOR; k++)
					for (int l = 0; l < SCALE_FACTOR; l++)
						mlx_pixel_put(mlx, window, i * SCALE_FACTOR + k, j * SCALE_FACTOR + l, ft_color(0, 0, 0));
			if (game->map[j][i] == '1')
				for (int k = 0; k < SCALE_FACTOR; k++)
					for (int l = 0; l < SCALE_FACTOR; l++)
						mlx_pixel_put(mlx, window, i * SCALE_FACTOR + k, j * SCALE_FACTOR + l, ft_color(120, 50, 0));
			if (game->map[j][i] == '0')
				for (int k = 0; k < SCALE_FACTOR; k++)
					for (int l = 0; l < SCALE_FACTOR; l++)
						mlx_pixel_put(mlx, window, i * SCALE_FACTOR + k, j * SCALE_FACTOR + l, ft_color(0, 120, 120));
			if (game->map[j][i] == '.')
				for (int k = 0; k < SCALE_FACTOR; k++)
					for (int l = 0; l < SCALE_FACTOR; l++)
						mlx_pixel_put(mlx, window, i * SCALE_FACTOR + k, j * SCALE_FACTOR + l, ft_color(30, 100, 0));
			if (game->map[j][i] == 'n')
			{
				int	posY = (int)(game->player->position->h * 10) % 10;
				int	posX = (int)(game->player->position->v * 10) % 10;
				printf("Position : %d %d\n", posX, posY);
				for (int k = posX; k < PLAYER_SIZE + posX; k++)
					for (int l = posY; l < PLAYER_SIZE + posY; l++)
						mlx_pixel_put(mlx, window, i * SCALE_FACTOR + k, j * SCALE_FACTOR + l, ft_color(230, 200, 0));
			}
			j++;
		}
		i++;
	}
}

void	render(void *param)
{
	void *mlx;
	void *window;
	t_game *game;
	double	ray_norm;

	mlx = ((void **) param)[0];
	window = ((void **) param)[1];
	game = ((void **) param)[2];
	game->player->camera->v = -1;
	game->player->camera->h = 0;
	display_map(mlx, window, game);
	for (int x = 0; x < WIDTH; x++)
	{
		ray_norm = get_distance_per_column(x, game);
		double	texture_height;

		if (ray_norm)
		{
			texture_height = (double)HEIGHT * (1 / ray_norm);
			for (int i = HEIGHT / 2 - texture_height / 2; i < HEIGHT / 2 + texture_height / 2; i++)
				mlx_pixel_put(mlx, window, x, i, ft_color(255, 0, 0));
		}
	}
}
