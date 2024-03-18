/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:03:37 by lribette          #+#    #+#             */
/*   Updated: 2024/03/18 13:30:20 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	choose_orientation(t_2dvector *camera, char c)
{
	camera->h = 0;
	camera->v = 0;
	if (c == 'N')
		camera->v = -1;
	else if (c == 'S')
		camera->v = 1;
	else if (c == 'E')
		camera->h = 1;
	else
		camera->h = -1;
}

void	check_chars(char **map, t_game *game)
{
	int	i;
	int	j;
	int	number_of_players;

	i = 0;
	number_of_players = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_a_map_char(map[i][j]) && !is_space(map[i][j]))
				exit_error("Invalid char", game);
			if (is_player(map[i][j]))
			{
				game->player->position->v = j + 1.25;
				game->player->position->h = i + 1.25;
				choose_orientation(game->player->camera, game->map[i][j]);
				number_of_players++;
			}
			j++;
		}
		i++;
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

char	**clean_map(char **map, t_game *game) {
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
			if (map[i][j] == '.')
				printf("\x1b[38;2;30;100;0m.\e[0m");
			else if (map[i][j] == '1')
				printf("\x1b[38;2;120;50;0m1\e[0m");
			else if (map[i][j] == '0')
				printf("\x1b[38;2;0;120;120m0\e[0m");
			else if (map[i][j] == ' ')
				printf(" \e[0m");
			else if (map[i][j] == 'n' || map[i][j] == 's'
				|| map[i][j] == 'w' || map[i][j] == 'e')
				printf("\x1b[38;2;230;200;0;5m\e[1m%c\e[0m", map[i][j]);
			else if (map[i][j] == 'o')
				printf("\x1b[38;2;0;200;0;1mo\e[0m");
			else if (map[i][j] == 'c')
				printf("\x1b[38;2;200;0;0;1mc\e[0m");
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
	if (!is_closed(game, game->player->position->h, game->player->position->v))
		printf("\x1b[38;2;180;0;0;7mUnclosed map\n\e[0m");
	print_map(game->map);
}
