/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/23 10:27:56 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "controls.h"
#include "render.h"
#include "vector/vector.h"

void	render(void *param)
{
	void	*mlx;
	void	*window;
	t_game	*game;
	int		*redraw;

	mlx = ((void **)param)[0];
	window = ((void **)param)[1];
	game = ((void **)param)[2];
	redraw = ((int **)param)[3];
	if (*redraw == 0)
		return ;
	display_map(game);
	display_game(game);
	mlx_put_image_to_window(game->texture->mlx, game->texture->window,
		game->texture->game, 0, 0);
	mlx_put_image_to_window(game->texture->mlx, game->texture->window,
		game->texture->map, 0, 0);
	*redraw = 0;
}

void	send_ray(t_game *game, double start_position, int color, int column)
{
	t_ray	ray;

	(void)color;
	ray.ray_start_pos[H] = game->player->position->h + (MOVEMENT / 2);
	ray.ray_start_pos[V] = game->player->position->v + MOVEMENT;
	ray.coords[H] = (int)ray.ray_start_pos[H];
	ray.coords[V] = (int)ray.ray_start_pos[V];
	get_ray_direction(&ray, *game->player, start_position);
	get_ray_dist_per_step(&ray);
	get_side_dists(&ray);
	search_for_a_wall(&ray, game);
	(void)column;
	get_line_height(game, column, &ray);
}

void	display_game(t_game *game)
{
	int	column;

	send_ray(game, (double)(-WIDTH) / (double)WIDTH, ft_color(255, 0, 0), 1);
	column = 1;
	while (column < WIDTH)
	{
		send_ray(game, (double)(column * 2 - WIDTH) / (double)WIDTH, 0, column);
		column++;
	}
	send_ray(game, (double)(column * 2 - WIDTH) / (double)WIDTH, ft_color(255,
			0, 0), WIDTH);
}

void	render_column(t_ray *ray, t_game *game, int col)
{
	int	color;
	int	l;

	l = 1;
	while (l < ray->line[0])
	{
		if (col > 0 && l > 0 && col < WIDTH && l < HEIGHT)
			my_mlx_pixel_put(game->texture->game, col, l, ft_color(42, 42, 420
					% 255));
		l++;
	}
	while (l < ray->line[1])
	{
		color = ft_color(60, 60, 60);
		if (ray->side == 1)
			color = ft_color(120, 120, 120);
		my_mlx_pixel_put(game->texture->game, col, l, color);
		l++;
	}
	while (l < HEIGHT)
	{
		my_mlx_pixel_put(game->texture->game, col, l, ft_color(420 % 255, 42,
				42));
		l++;
	}
}
