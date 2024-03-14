/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:25:27 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 13:46:06 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

 # include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

enum	e_directions
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct s_textures
{
	// mlx_image	wall[4];
	// mlx_image	door[4];
	int			floor;
	int			ceiling;
}				t_textures;

typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct s_game
{
	t_textures	*texture;
	t_player	player;
	int			longest_line;
	int			parsing_error;
	char		**map;
}				t_game;

void	parse_map(int fd, t_game *game);

#endif
