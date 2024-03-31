/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:49:24 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/31 15:19:40 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

typedef struct s_textures	t_textures;
typedef struct s_player		t_player;

typedef struct s_game
{
	t_textures				*texture;
	t_player				*player;
	int						longest_line;
	char					**map;
}							t_game;

void						free_mlx(t_textures *texture);
t_game						*init_game(void);
void						free_game(t_game *game, int free_textures);
void						run_game(t_game *game, long *redraw);

#endif
