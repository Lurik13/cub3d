/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:03:37 by lribette          #+#    #+#             */
/*   Updated: 2024/03/14 13:49:27 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space(char c)
{
	if (/*(c >= 9 && c <= 13) || */c == ' ' || c == '\n')
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	is_a_map_char(char c)
{
	if (is_player(c) || c == '1' || c == '0' || c == 'O' || c == 'C')
		return (1);
	return (0);
}

void	free_table(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
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
			if (!is_a_map_char(map[i][j]) && map[i][j] != ' ' && map[i][j] != '\n')
			{
				printf("\x1b[38;2;180;0;0;7mInvalid char\n\e[0m");
				free_table(map);
				exit(EXIT_FAILURE);
			}
			if (is_player(map[i][j]))
			{
				game->player.x = j;
				game->player.y = i;
				number_of_players++;
			}
			j++;
		}
		i++;
	}
	if (number_of_players != 1)
	{
		printf("\x1b[38;2;180;0;0;7m\033[5mWrong number of players\n\e[0m");
		free_table(map);
		exit(EXIT_FAILURE);
	}
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (tab)
		while (tab[i])
			i++;
	return (i);
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
		if (!str[i - 1] || is_space(str[i - 1])/* || i == len*/ || extremity)
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
	printf("\n\n%s\n", new[0]);
	while (i < len + 1)///////////////
	{
		new[i] = dup_replacing_by_dots(map[i - 1], 0, game->longest_line);
		printf("%s\n", new[i]);
		i++;
	}
	new[i] = dup_replacing_by_dots(map[i - 2], 1, game->longest_line);
	printf("%s\n", new[i]);
	free_table(map);
	return (new);
}

static int	is_checked(char c)
{
	if (is_player(c) || c == '0' || c == 'O' || c == 'C' || c == '.')
		return (0);
	return (1);
}

void	is_closed(t_game *game, int y, int x)
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
	else if (game->map[y][x] == '.')
	{
		game->parsing_error = 1;
		return ;
	}
	if (!is_checked(game->map[y][x + 1]))
		is_closed(game, y, x + 1);
	if (!is_checked(game->map[y][x - 1]))
		is_closed(game, y, x - 1);
	if (!is_checked(game->map[y + 1][x]))
		is_closed(game, y + 1, x);
	if (!is_checked(game->map[y - 1][x]))
		is_closed(game, y - 1, x);
}

void	parse_map(int fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line || line[0] == '\0')
		printf("Map missing\n");//ft_error("Map missing");
	game->longest_line = ft_strlen(line);
	game->map = malloc((16) * sizeof(char *));
	game->parsing_error = 0;
	if (!game->map)
		printf("Malloc failed\n");//ft_error("Malloc failed");
	i = 0;
	while (line)
	{
		if ((int)ft_strlen(line) > game->longest_line)
			game->longest_line = ft_strlen(line);
		game->map[i] = line;
		printf("game->map[%d] = %s\n", i, game->map[i]);
		i++;
		if (i % 16 == 0)
			game->map = ft_grow(game->map, (i - 15) * sizeof(char *),
			(i + 1) * sizeof(char *));
		line = get_next_line(fd);
	}
	
	check_chars(game->map, game);
	game->map = clean_map(game->map, game);
	is_closed(game, game->player.y, game->player.x);
	i = 0;
	printf("\n\n3eme etape :\n");
	while (game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	if (game->parsing_error)
	{
		printf("\x1b[38;2;180;0;0;7mUnclosed map\n\e[0m");
		free_table(game->map);
	}
}
