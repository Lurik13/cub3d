/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:37:11 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/24 13:46:06 by aboyreau         ###   ########.fr       */
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
			my_mlx_pixel_put(game->texture->game, col, l, game->texture->ceiling);
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
		my_mlx_pixel_put(game->texture->game, col, l, game->texture->floor);
		l++;
	}
}

int	get_pixel_color(void *data, int h, int v)
{
	t_data	img_data;

	img_data.img = data;
	img_data.addr = mlx_get_data_addr(data, &img_data.bits_per_pixel,
			&img_data.line_length, &img_data.endian);
	return (*(int *)(img_data.addr \
			+ (4 * TEXTURE_WIDTH * v) \
			+ (4 * h)));
}

void	render_textured_column(t_ray *ray, t_game *game, int col)
{
	int		text_coords[2];
	double	wall[2];

	if (ray->side == 0)
		wall[H] = ray->ray_start_pos[V] + ray->distance * ray->ray_dir[V];
	else
		wall[H] = ray->ray_start_pos[H] + ray->distance * ray->ray_dir[H];
	wall[H] -= (int) wall[H];
	text_coords[H] = (int)(wall[H] * (double)TEXTURE_WIDTH);
	if (ray->side == 0 && ray->ray_dir[H] > 0)
		text_coords[H] = TEXTURE_WIDTH - text_coords[H] - 1;
	if (ray->side == 1 && ray->ray_dir[V] < 0)
		text_coords[H] = TEXTURE_WIDTH - text_coords[H] - 1;

	int		h;
	double	step;
	double	text_pos;
	double	line_height;

	line_height = HEIGHT / ray->distance;
	step = 1.0 * (double)TEXTURE_HEIGHT / line_height;
	text_pos = (ray->line[0] - HEIGHT / 2 + line_height / 2) * step;
	h = ray->line[0];
	printf("from %d to %d\n", ray->line[0], ray->line[1]);
	while (h < ray->line[1])
	{
		text_coords[V] = (int)text_pos & (TEXTURE_HEIGHT - 1);
		text_pos += step;
		int color = get_pixel_color(game->texture->wall[0], h, col);
		printf("color : %d in %d %d\n", color, text_coords[H], text_coords[V]);
		my_mlx_pixel_put(game->texture->game, text_coords[H], text_coords[V], color);
		h++;
	}
	printf("Rendered !\n");
}
