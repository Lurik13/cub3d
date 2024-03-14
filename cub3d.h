/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:25:27 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 10:35:46 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

enum	e_directions
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct s_textures
{
	mlx_image	wall[4];
	mlx_image	door[4];
	int			floor;
	int			ceiling;
}				t_textures;

typedef struct s_game
{
	t_textures	texturedata;
	char		**map;
}				t_game;

#endif
