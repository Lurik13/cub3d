/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:03:37 by lribette          #+#    #+#             */
/*   Updated: 2024/03/14 11:23:10 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
# include "./libft/libft.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	is_a_map_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == '1' || c == '0' || c == 'O' || c == 'C')
		return (1);
	return (0);
}

void	parse_map(int fd, t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line || line[0] == '\0')
		printf("Map missing\n");//ft_error("Map missing");
	game->map = malloc((16) * sizeof(char *));
	if (!game->map)
		printf("Malloc failed\n");//ft_error("Malloc failed");
	i = 1;
	while (line)
	{
		game->map[i] = line;
		printf("game->map[i] = %s\n", game->map[i]);
		i++;
		if (i % 16 == 0)
			game->map = ft_grow(game->map, (i - 15) * sizeof(char *),
			(i + 1) * sizeof(char *));
		line = get_next_line(fd);
	}
	
}
