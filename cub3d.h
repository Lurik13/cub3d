/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:25:27 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 10:54:43 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "mlx.h"

enum	e_directions
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct s_textures
{
	void		*wall[4];
	void		*door[4];
	int			floor;
	int			ceiling;
}				t_textures;

typedef struct s_game
{
	t_textures	*texture;
	char		**map;
}				t_game;

#endif
