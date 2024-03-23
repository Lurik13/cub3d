/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:25:27 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/23 08:32:50 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

enum	e_directions
{
	NORTH = 0,
	SOUTH,
	EAST,
	WEST
};

typedef struct s_textures
{
	void		*mlx;
	void		*map;
	void		*game;
	void		*window;
	void		*wall[4];
	void		*door[4];
	int			floor;
	int			ceiling;
}				t_textures;

typedef struct s_player
{
	t_2dvector	*position;
	t_2dvector	*camera;
	t_2dvector	fov;
}				t_player;

typedef struct s_game
{
	t_textures	*texture;
	t_player	*player;
	int			longest_line;
	char		**map;
}				t_game;

/* ************************************************************************* */
/* Libft (todo)																 */
/* ************************************************************************* */
int		ft_tablen(char **tab);

/* ************************************************************************* */
/* parser.c																	 */
/* ************************************************************************* */
int	parse_attrs(int fd, t_game **game);
void	parse_map(int fd, t_game *game);

/* ************************************************************************* */
/* check_map.c																 */
/* ************************************************************************* */
void	check_chars(char **map, t_game *game);
int		is_space(char c);
int		is_player(char c);
int		is_a_map_char(char c);
int		is_closed(t_game *game, int y, int x);

/* ************************************************************************* */
/* Game																		 */
/* ************************************************************************* */
void	free_game(t_game *game);
t_game	*init_game(void);
void	free_table(char **tab);

/* ************************************************************************* */
/* Cub3d																	 */
/* ************************************************************************* */
void	exit_error(char *str, t_game *game);

#endif
