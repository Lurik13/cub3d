/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:03:37 by lribette          #+#    #+#             */
/*   Updated: 2024/03/27 15:45:59 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static void	ft_rotate(t_player *player, double orientation)
{
	t_2dvector	old_fov;
	t_2dvector	old_camera;

	old_fov.h = player->fov.h;
	old_fov.v = player->fov.v;
	old_camera.h = player->camera->h;
	old_camera.v = player->camera->v;
	player->camera->h = old_camera.h * cos(orientation * ROTATION_SPEED)
		- player->camera->v * sin(orientation * ROTATION_SPEED);
	player->camera->v = old_camera.h * sin(orientation * ROTATION_SPEED)
		+ player->camera->v * cos(orientation * ROTATION_SPEED);
	player->fov.h = old_fov.h * cos(orientation * ROTATION_SPEED)
		- player->fov.v * sin(orientation * ROTATION_SPEED);
	player->fov.v = old_fov.h * sin(orientation * ROTATION_SPEED)
		+ player->fov.v * cos(orientation * ROTATION_SPEED);
}

void	choose_orientation(t_player *player, char c)
{
	player->camera->v = -1;
	player->fov.h = 0.66;
	if (c == 'S')
		ft_rotate(player, 32);
	else if (c == 'E')
		ft_rotate(player, 16);
	else if (c == 'W')
		ft_rotate(player, 48);
}

void	check_chars(char **map, t_game *game)
{
	int	v;
	int	h;
	int	number_of_players;

	v = 0;
	number_of_players = 0;
	while (map[v])
	{
		h = 0;
		while (map[v][h])
		{
			if (!is_a_map_char(map[v][h]) && !is_space(map[v][h]))
				exit_error("Invalid char", game);
			if (is_player(map[v][h]))
			{
				game->player->position->v = v + 1.375;
				game->player->position->h = h + 1.375;
				choose_orientation(game->player, game->map[v][h]);
				number_of_players++;
			}
			h++;
		}
		v++;
	}
	if (number_of_players != 1)
		exit_error("Wrong number of players", game);
}

char	*dup_replacing_by_dots(char *str, int extremity, int len)
{
	int		i;
	char	*new;

	if (!str)
		return (NULL);
	new = ft_calloc(len + 2, sizeof(char));
	if (!new)
		return (NULL);
	new[0] = '.';
	i = 1;
	while (i < len + 1)
	{
		if (i > (int)ft_strlen(str)
			|| (str[i - 1] && is_space(str[i - 1])) || extremity)
			new[i] = '.';
		else
			new[i] = str[i - 1];
		i++;
	}
	return (new);
}

char	**clean_map(char **map, t_game *game)
{
	int		i;
	char	**new;
	int		len;

	len = ft_tablen(map);
	new = ft_calloc(len + 2 + 1, sizeof(char *));
	if (!new)
		return (NULL);
	i = 1;
	new[0] = dup_replacing_by_dots(map[i], 1, game->longest_line);
	while (i < len + 1)
	{
		new[i] = dup_replacing_by_dots(map[i - 1], 0, game->longest_line);
		i++;
	}
	new[i] = dup_replacing_by_dots(map[i - 2], 1, game->longest_line);
	free_table(map);
	return (new);
}

void	print_char(char c)
{
	if (c == '.')
		printf(DOT_MSG);
	if (c == '0')
		printf(ZERO_MSG);
	if (c == '1')
		printf(ONE_MSG);
	if (c == ' ')
		printf(SPACE_MSG);
	if (c == 'n')
		printf(N_MSG);
	if (c == 's')
		printf(S_MSG);
	if (c == 'e')
		printf(E_MSG);
	if (c == 'w')
		printf(W_MSG);
	if (c == 'o')
		printf(O_MSG);
	if (c == 'c')
		printf(C_MSG);
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			print_char(map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	parse_map(int fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line || line[0] == '\0')
		printf("Map missing\n");
	game->longest_line = ft_strlen(line);
	game->map = ft_calloc(16, sizeof(char *));
	if (!game->map)
		printf("Malloc failed\n");
	i = 0;
	while (line)
	{
		if ((int)ft_strlen(line) > game->longest_line)
			game->longest_line = ft_strlen(line);
		game->map[i] = line;
		i++;
		if (i % 16 == 0)
		{
			game->map = ft_grow(game->map, i * sizeof(char *),
					(i + 15) * sizeof(char *));
		}
		line = get_next_line(fd);
	}
	check_chars(game->map, game);
	game->map = clean_map(game->map, game);
	is_closed(game, game->player->position->v, game->player->position->h);
	print_map(game->map);
}
