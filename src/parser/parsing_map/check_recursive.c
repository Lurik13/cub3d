/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:01:37 by lribette          #+#    #+#             */
/*   Updated: 2024/03/15 12:33:49 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_checked(char c)
{
	if (is_player(c) || c == '0' || c == 'O' || c == 'C' || c == '.')
		return (0);
	return (1);
}

static void	replace_chars(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
		game->map[y][x] = ' ';
	else if (game->map[y][x] == 'N')
		game->map[y][x] = 'n';
	else if (game->map[y][x] == 'S')
		game->map[y][x] = 's';
	else if (game->map[y][x] == 'W')
		game->map[y][x] = 'w';
	else if (game->map[y][x] == 'E')
		game->map[y][x] = 'e';
	else if (game->map[y][x] == 'O')
		game->map[y][x] = 'o';
	else if (game->map[y][x] == 'C')
		game->map[y][x] = 'c';
}

int	is_closed(t_game *game, int y, int x)
{
	replace_chars(game, y, x);
	if (game->map[y][x] == '.')
		return (1);
	if (!is_checked(game->map[y][x + 1]))
		is_closed(game, y, x + 1);
	if (!is_checked(game->map[y][x - 1]))
		is_closed(game, y, x - 1);
	if (!is_checked(game->map[y + 1][x]))
		is_closed(game, y + 1, x);
	if (!is_checked(game->map[y - 1][x]))
		is_closed(game, y - 1, x);
	return (0);
}
