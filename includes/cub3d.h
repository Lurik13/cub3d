/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:25:27 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/28 10:58:51 by aboyreau         ###   ########.fr       */
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
# include <math.h>

# define DOT_MSG "\x1b[38;2;30;100;0m.\e[0m"
# define ZERO_MSG "\x1b[38;2;0;120;120m0\e[0m"
# define ONE_MSG "\x1b[38;2;120;50;0m1\e[0m"
# define SPACE_MSG " "
# define N_MSG "\x1b[38;2;230;200;0;5m\e[1mn\e[0m"
# define S_MSG "\x1b[38;2;230;200;0;5m\e[1ms\e[0m"
# define E_MSG "\x1b[38;2;230;200;0;5m\e[1me\e[0m"
# define W_MSG "\x1b[38;2;230;200;0;5m\e[1mw\e[0m"
# define O_MSG "\x1b[38;2;0;200;0;1mo\e[0m"
# define C_MSG "\x1b[38;2;200;0;0;1mc\e[0m"
# define RED "\x1b[38;2;180;0;0;7m"
# define RESET "\n\e[0m"

#define ROTATION_SPEED 0.1

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

void	choose_orientation(t_player *player, char c);
void	print_map(char **map);

/* ************************************************************************* */
/* Game																		 */
/* ************************************************************************* */
void	free_game(t_game *game, int free_textures);
t_game	*init_game(void);
void	free_table(char **tab);

/* ************************************************************************* */
/* Cub3d																	 */
/* ************************************************************************* */
void	exit_error(char *str, t_game *game);

#endif
