/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:24:59 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 11:55:35 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"
#include "printf/ft_printf.h"
#include "str/ft_str.h"
#include <unistd.h>

int	parse_attr(void *mlx, char *line, t_game *game)
{
	int	direction;

	direction = -1;
	if (ft_strstartswith(line, "C"))
		game->texture->ceiling = ft_color(ft_atoi(line + 2), ft_atoi(ft_strchr(line, ',')), ft_atoi(ft_strrchr(line, ',')));
	if (ft_strstartswith(line, "F"))
		game->texture->floor = ft_color(ft_atoi(line + 2), ft_atoi(ft_strchr(line, ',')), ft_atoi(ft_strrchr(line, ',')));
	if (ft_strstartswith(line, "NO"))
		direction = NORTH;
	else if (ft_strstartswith(line, "SO"))
		direction = SOUTH;
	else if (ft_strstartswith(line, "WE"))
		direction = WEST;
	else if (ft_strstartswith(line, "EA"))
		direction = EAST;
	if (direction != -1)
		game->texture->wall[direction] = mlx_xpm_to_image(mlx, &line, NULL, NULL);
	if (game->texture->wall[direction] == NULL || direction == -1)
	{
		ft_dprintf(STDERR_FILENO, "Cannot load the texture %s\n", line + 3);
		return (1);
	}
	return (0);
}

int	parse_attrs(void *mlx, int fd, t_game *game)
{
	char	*temp;
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
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
	int	i;
	i = 0;
	while (i < 4)
		printf("texture : %p\n", game->texture->wall[i++]);
	return (0);
}
