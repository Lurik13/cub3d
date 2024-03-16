/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/16 11:24:00 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../libft/math/math.h"
#include "vector/vector.h"
#include <float.h>

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

void	render(void *mlx, t_game *game)
{
	void	*window;

	window = mlx_new_window(mlx, WIDTH, HEIGHT, "2D2R");
	if (window == NULL)
		return (exit_error("Couldn't create the window\n", game));

	double		ray[2];
	double		ray_dist_per_step[2];
	// double		how_far_from_side[2];
	t_2dvector	fov;
	double		cameraX;

	fov.h = 0;
	fov.v = 0.66f;
	// game->player->camera->h = -1;
	printf("Initial camera angle : %lf %lf\n", game->player->camera->h, game->player->camera->v);
	while(1) // TODO replace with mlx loop and put the content in a mlx hook
	{
		for (int x = 0; x < WIDTH; x++)
		{
			cameraX = 2 * x / (double)WIDTH - 1;
			get_ray_direction(ray, *game->player->camera, fov, cameraX);
			get_ray_dist_per_step(ray_dist_per_step, ray);
			printf("%lf %lf\n", ray_dist_per_step[DIRX], ray_dist_per_step[DIRY]);
			// get_how_far_from_side_the_ray_is();
		}
		break ;
	}
	mlx_destroy_window(mlx, window);
}
