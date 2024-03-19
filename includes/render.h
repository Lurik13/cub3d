/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:52:56 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/19 07:19:16 by aboyreau         ###   ########.fr       */
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

/**
 * @brief Propagate a ray until a wall is met.
 * @param `game` The game structure.
 * @param `start_position` The column of the screen from which the ray
 * should start.
 */
void	send_ray(t_game *game, double start_position, int color);

void	display_map(t_game *game);

void	render(void *param);

#endif
