/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <aboyreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/31 14:20:19 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "cub3d.h"
#include "render.h"
#include "vector/vector.h"
#include <math.h>

void	render(void *param)
{
	t_game	*game;
	int		*redraw;

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
	ray.ray_start_pos[H] = game->player->position->h;
	ray.ray_start_pos[V] = game->player->position->v;
	ray.coords[H] = (int)ray.ray_start_pos[H];
	ray.coords[V] = (int)ray.ray_start_pos[V];
	get_ray_direction(&ray, *game->player, start_position);
	get_ray_dist_per_step(&ray);
	get_side_dists(&ray);
	search_for_a_wall(&ray, game);
	get_line_height(game, column, &ray);
}

void	display_game(t_game *game)
{
	int	column;

	column = 0;
	while (column < WIDTH)
	{
		send_ray(game, (double)(column * 2 - WIDTH) / (double)WIDTH, 0, column);
		column++;
	}
}

int	get_pixel_color(void *data, double h, double v)
{
	t_data	img_data;

	img_data.img = data;
	img_data.addr = mlx_get_data_addr(data, &img_data.bits_per_pixel,
			&img_data.line_length, &img_data.endian);
	return (*(int *)(img_data.addr + (4 * TEXTURE_WIDTH * (int)v) + (4 * (int)h)));
}

void	textures_rendering_one(t_ray *ray, double text_coords[2], double *wallh)
{
	if (ray->side == 0)
		*wallh = ray->ray_start_pos[V] + ray->distance * ray->ray_dir[V];
	else
		*wallh = ray->ray_start_pos[H] + ray->distance * ray->ray_dir[H];
	*wallh = fmod(*wallh, 1.0);
	text_coords[H] = (int)(*wallh * (double)TEXTURE_WIDTH);
	if (ray->side == 0 && ray->ray_dir[H] < 0)
		text_coords[H] = TEXTURE_WIDTH - text_coords[H] - 1;
	if (ray->side == 1 && ray->ray_dir[V] > 0)
		text_coords[H] = TEXTURE_WIDTH - text_coords[H] - 1;
}

void	render_textured_column(t_ray *ray, t_game *game, int col)
{
	double	text_coords[2];
	double	wallh;
	int		v;
	double	step;
	int		color;

	v = 0;
	text_coords[V] = 0;
	textures_rendering_one(ray, text_coords, &wallh);
	step = (double)TEXTURE_HEIGHT / (ray->line[1] - ray->line[0]);
	if (ray->line[0] < 0)
		text_coords[V] = ft_abs(ray->line[0]) * step;
	while (v < ray->line[0])
		my_mlx_pixel_put(game->texture->game, col, v++, game->texture->ceiling);
	while (v < ray->line[1])
	{
		if (v >= 0)
		{
			color = get_pixel_color(game->texture->wall[ray->texture_index],
					text_coords[H], text_coords[V]);
			my_mlx_pixel_put(game->texture->game, col, v, color);
		}
		text_coords[V] += step;
		v++;
	}
	while (v < HEIGHT)
		my_mlx_pixel_put(game->texture->game, col, v++, game->texture->floor);
}
