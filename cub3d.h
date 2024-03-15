/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:25:27 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/15 04:38:24 by aboyreau         ###   ########.fr       */
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

typedef struct s_player
{
	int	x;
	int	y;
	int	camera;
}				t_player;

typedef struct s_game
{
	t_textures	*texture;
	t_player	player;
	int			longest_line;
	int			parsing_error;
	char		**map;
}				t_game;

/* ************************************************************************* */
/* check_recursive.c														 */
/* ************************************************************************* */
int	is_closed(t_game *game, int y, int x);

/* ************************************************************************* */
/* parsing_map.c															 */
/* ************************************************************************* */
void	check_chars(char **map, void *mlx, t_game *game);
void	parse_map(int fd, void *mlx, t_game *game);

/* ************************************************************************* */
/* parsing_utils.c															 */
/* ************************************************************************* */
int		is_space(char c);
int		is_player(char c);
int		is_a_map_char(char c);
void	free_table(char **tab);
int		ft_tablen(char **tab);

int		parse_attrs(void *mlx, int fd, t_game **game);
void	free_game(void *mlx, t_game *game);
t_game	*init_game(void);
void	exit_error(char *str, void *mlx, t_game *game);

#endif
