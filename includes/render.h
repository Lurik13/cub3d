/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:52:56 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/20 12:26:31 by aboyreau         ###   ########.fr       */
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
}		t_ray;

/**
 * @brief Propagate a ray until a wall is met.
 * @param `game` The game structure.
 * @param `start_position` The column of the screen from which the ray
 * should start.
 */
void	search_for_a_wall(t_ray *ray, t_game *game, int col);

void	display_map(t_game *game);

void	render(void *param);

void	display_square(t_game *game, int colour, int h_start, int v_start);

void	get_side_dists(t_ray *ray);

void	send_ray(t_game *game, double start_position, int color, int column);

#endif
