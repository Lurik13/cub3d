/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:24:59 by aboyreau          #+#    #+#             */
/*   Updated: 2024/04/08 17:56:11 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"
#include "printf/ft_printf.h"
#include "str/ft_str.h"
#include <unistd.h>

int	parse_color(char *line, t_game *game, int color)
{
	if (ft_strstartswith(line, "C"))
	{
		if (game->texture->ceiling != -1)
			return (-1);
		game->texture->ceiling = color;
	}
	else if (ft_strstartswith(line, "F"))
	{
		if (game->texture->floor != -1)
			return (-1);
		game->texture->floor = color;
		return (1);
	}
	return (1);
}

/**
 * @return 0 if no colors were found, 1 if a valid floor or ceiling color
 * was found, -1 if an invalid floor or ceiling is found.
 */
int	parse_colors(char *line, t_game **game)
{
	int	i;
	int	r;
	int	g;
	int	b;

	if (ft_strstartswith(line, "C") || ft_strstartswith(line, "F"))
	{
		i = 0;
		while (line[i])
			if (!ft_strcontains("0123456789,CF\n ", line[i++]))
				return (1);
		if (ft_strcount(',', line) != 2)
			return (-1);
		if (!((ft_strcount('C', line) == 1 && ft_strcount('F', line) == 0)
				|| (ft_strcount('F', line) == 1 && !ft_strcount('C', line))))
			return (-1);
		r = ft_atoi(line + 2);
		g = ft_atoi(ft_strchr(line, ',') + 1);
		b = ft_atoi(ft_strrchr(line, ',') + 1);
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
			return (-1);
		return (parse_color(line, *game, ft_color(r, g, b)));
	}
	return (0);
}

int	parse_attr(char *line, t_game **game)
{
	int	direction;
	int	err;

	direction = -1;
	err = parse_colors(line, game);
	if (err)
		return (err - 1);
	if (ft_strstartswith(line, "NO"))
		direction = NORTH;
	else if (ft_strstartswith(line, "SO"))
		direction = SOUTH;
	else if (ft_strstartswith(line, "WE"))
		direction = WEST;
	else if (ft_strstartswith(line, "EA"))
		direction = EAST;
	line += 2;
	while (ft_strcontains(" ", *line))
		line++;
	if (direction == -1 || (*game)->texture->wall[direction] != NULL)
		return (-1);
	(*game)->texture->wall[direction] = ft_strdup(line);
	if ((*game)->texture->wall[direction] == NULL)
		return (1);
	return (0);
}

int	textures_check(t_textures *tex)
{
	int	i;

	i = 0;
	if (tex->ceiling == -1)
		return (0);
	if (tex->floor == -1)
		return (0);
	while (i < 4)
		if (tex->wall[i++] == NULL)
			return (0);
	return (1);
}

int	parse_attrs(int fd, t_game **game)
{
	char	*temp;
	char	*line;

	line = "";
	while (!textures_check((*game)->texture) && line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = line;
		line = ft_strtrim(line, " \n");
		free(temp);
		if (line[0] != '\0')
		{
			if (parse_attr(line, game))
			{
				free(line);
				return (-1);
			}
		}
		free(line);
	}
	if (line == NULL)
		return (-1);
	return (0);
}
