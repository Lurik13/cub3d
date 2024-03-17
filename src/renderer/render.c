/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/17 09:21:34 by aboyreau         ###   ########.fr       */
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
	// double		how_far_from_side[2];
	t_2dvector	fov;
	double		cameraX;

	fov.h = 0;
	fov.v = 0.66f;
	cameraX = 2 * column / (double)WIDTH - 1;
	ray_pos[DIRX] = game->player->position->h;
	ray_pos[DIRY] = game->player->position->v;
	get_ray_direction(ray, *game->player->camera, fov, cameraX);
	get_ray_dist_per_step(ray_dist_per_step, ray);
	// printf("%lf %lf\n", ray_dist_per_step[DIRX], ray_dist_per_step[DIRY]);
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
				for (int k = 3; k < SCALE_FACTOR - 3; k++)
					for (int l = 3; l < SCALE_FACTOR - 3; l++)
						mlx_pixel_put(mlx, window, i * SCALE_FACTOR + k, j * SCALE_FACTOR + l, ft_color(230, 200, 0));
			j++;
		}
		i++;
	}
}

void	render(void *mlx, t_game *game)
{
	void	*window;
	double	ray_norm;

	window = mlx_new_window(mlx, WIDTH, HEIGHT, "2D2R");
	if (window == NULL)
		return (exit_error("Couldn't create the window\n", game));
	game->player->camera->v = -1;
	game->player->camera->h = 0;
	display_map(mlx, window, game);
	while(1) // TODO replace with mlx loop and put the content in a mlx hook
	{
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
		break ;
	}
	sleep(5);
	mlx_destroy_window(mlx, window);
}

// void get_how_far_from_side_the_ray_is(double distances[2], int pos[2],
// 		float	ray_direction[2], int *stepX, int *stepY,
// 		int ray_pos[2], double dist_per_step[2])
// {
// 	if (ray_direction[DIRX] < 0)
// 	{	
// 		*stepX = -1;
// 		distances[DIRX] = (pos[DIRX] - ray_pos[DIRX]) * dist_per_step[DIRX];
// 	}
// 	else
// 	{
// 		*stepX = 1;
// 		distances[DIRX] = (ray_pos[DIRX] + 1 - pos[DIRX]) * dist_per_step[DIRX];
// 	}
// 	if (ray_direction[DIRY] < 0)
// 	{	
// 		*stepY = -1;
// 		distances[DIRY] = (pos[DIRY] - ray_pos[DIRY]) * dist_per_step[DIRY];
// 	}
// 	else
// 	{
// 		*stepY = 1;
// 		distances[DIRY] = (ray_pos[DIRY] + 1 - pos[DIRY]) * dist_per_step[DIRY];
// 	}
// }
//
