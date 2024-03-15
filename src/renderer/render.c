/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/15 12:47:29 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../libft/math/math.h"
#include "vector/vector.h"

#define POSITION 0
#define DIRECTION 1

void	render(void *mlx, t_game *game)
{
	void	*window;

	window = mlx_new_window(mlx, WIDTH, HEIGHT, "2D2R");
	if (window == NULL)
		return (exit_error("Couldn't create the window\n", game));

	// raycasting
	t_2dvector	plane;
	t_2dvector	ray[2];
	t_2dvector	*camera[2];

	camera[POSITION] = game->player->position;
	camera[DIRECTION] = game->player->camera;
	plane.h = 0;
	plane.v = 0.66f;
#ifdef DEBUG
	ft_printf("I should render the map %p, at coords %d %d, " \
		"with a camera direction %d %d\n", game->map, position->v, \
		position->h, camera->v, camera->h);
#endif
	while(1)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			camera[POSITION]->h = 2 * x / (double)WIDTH - 1;
			ray[DIRECTION].h = camera[POSITION]->h + plane.h * camera[POSITION]->h;
			ray[DIRECTION].v = camera[POSITION]->v + plane.v * camera[POSITION]->h;
			// ft_printf("Pixel : %d\nRay pos : %d,%d\nRay dir : %d,%d\n",
			// 		x,
			// 		camera[POSITION]->h,
			// 		camera[POSITION]->v,
			// 		ray[DIRECTION].h,
			// 		ray[DIRECTION].v);
		}
		break ;
	}

	mlx_destroy_window(mlx, window);
}
