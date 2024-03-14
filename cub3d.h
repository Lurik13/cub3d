/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:25:27 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 12:50:59 by aboyreau         ###   ########.fr       */
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
	NORTH = 0,
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

void	parse_map(int fd, t_game *game);
int		parse_attrs(void *mlx, int fd, t_game **game);
void	free_game(void *mlx, t_game *game);
t_game	*init_game(void);

#endif
