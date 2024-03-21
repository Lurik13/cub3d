/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:52:56 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/21 07:26:33 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "mlx.h"
# include "libft.h"
# include "cub3d.h"
# include <float.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 1024

# define H 0
# define V 1

# define SCALE_FACTOR 24
# define PLAYER_SIZE 6

typedef struct	s_ray
{
	double	ray_start_pos[2];
	double	ray_dir[2];
	double	ray_dist_per_step[2];
	double	side_dist[2];
	int	step[2];
	int	coords[2];
	int	side;
	int	line[2];
	double	distance;
}		t_ray;

/* ************************************************************************** */
/*	DDA																		  */
/* ************************************************************************** */

/**
 * @brief Calculate the direction of the ray.
 * @param `ray` The state of the current ray.
 * @param `player` The current player informations (we need the camera and the fov !).
 * @param `start_position` The starting point of the ray.
 */
void	get_ray_direction(t_ray *ray, t_player player, double start_position);

/**
 * @brief Calculate how much the priority of the horizontal and vertical
 * direction should vary each iteration of the DDA.
 * @param `ray` The state of the current ray.
 */
void	get_ray_dist_per_step(t_ray *ray);

/**
 * @brief Calculates the priority of horizontal movements and of vertical movements.
 * Also calculates if the movement should go up, down, left or right.
 * @param `ray` The current ray informations.
 */
void	get_side_dists(t_ray *ray);

/**
 * @brief Propagate a ray until a wall is met.
 * @param `game` The game structure.
 * @param `start_position` The column of the screen from which the ray
 * should start.
 */
void	search_for_a_wall(t_ray *ray, t_game *game);

/**
 * @brief Calculates the height of the line to draw.
 * @param `game` The state of the current game.
 * @param `col` The color of the ray if it should be displayed on the map.
 * If col is 0, it shouldn't be displayed on the map.
 * @param `ray` The state of the ray.
 */
void	get_line_height(t_game *game, int col, t_ray *ray);

/* ************************************************************************** */
/*	DDA																		  */
/* ************************************************************************** */

/**
 * @brief render the map
 * @param `game` the struct containing the game state.
 */
void	display_map(t_game *game);

/**
 * @brief Renders the screen.
 */
void	render(void *param);

/**
 * @brief Send a ray.
 * @param `game` The state of the game.
 * @param `start_position` The starting position of the ray as a double (`(screen column * 2 - WIDTH) / (double) WIDTH`)
 * @param `color` The color of the ray on the minimap (or 0 if it should be hidden).
 * @param `column` The column on the screen for which we cast a ray.
 */
void	send_ray(t_game *game, double start_position, int color, int column);

/**
 * @brief Draw a column according to the ray structure.
 * @param `ray` A precalculated ray structure.
 * @param `game` The game state.
 * @param `col` The screen column.
 */
void	render_column(t_ray *ray, t_game *game, int col);

void	display_ray(t_ray ray, int color, t_game *game);

#endif
