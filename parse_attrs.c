/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:24:59 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 12:49:45 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"
#include "printf/ft_printf.h"
#include "str/ft_str.h"
#include <unistd.h>

int	parse_colors(char *line, t_game **game)
{
	if (ft_strstartswith(line, "C"))
	{
		(*game)->texture->ceiling = ft_color(\
			ft_atoi(line + 2), \
			ft_atoi(ft_strchr(line, ',')), \
			ft_atoi(ft_strrchr(line, ',')) \
		);
		return (1);
	}
	if (ft_strstartswith(line, "F"))
	{
		(*game)->texture->floor = ft_color(\
			ft_atoi(line + 2), \
			ft_atoi(ft_strchr(line, ',')), \
			ft_atoi(ft_strrchr(line, ',')) \
		);
		return (1);
	}
	return (0);
}

void	*load_texture(void *mlx, char *path)
{
	int		index;
	void	*texture;

	texture = mlx_xpm_file_to_image(mlx, path, &index, &index);
	if (texture == NULL)
		ft_dprintf(STDERR_FILENO, "Cannot load the texture %s\n", path);
	return (texture);
}

int	parse_attr(void *mlx, char *line, t_game **game)
{
	int	direction;

	direction = -1;
	if (parse_colors(line, game))
		return (0);
	if (ft_strstartswith(line, "NO"))
		direction = NORTH;
	else if (ft_strstartswith(line, "SO"))
		direction = SOUTH;
	else if (ft_strstartswith(line, "WE"))
		direction = WEST;
	else if (ft_strstartswith(line, "EA"))
		direction = EAST;
	line += 2;
	while (ft_strcontains(" \t", *line))
		line++;
	(*game)->texture->wall[direction] = load_texture(mlx, line);
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

int	parse_attrs(void *mlx, int fd, t_game **game)
{
	char	*temp;
	char	*line;

	line = get_next_line(fd);
	while (!textures_check((*game)->texture))
	{
		temp = line;
		line = ft_strtrim(line, " \t\r\n");
		free(temp);
		if (line[0] != '\0')
			if (parse_attr(mlx, line, game))
				return (-1);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
