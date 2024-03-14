/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:24:59 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 11:22:21 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"
#include "printf/ft_printf.h"
#include "str/ft_str.h"
#include <unistd.h>

void	parse_attr(void *mlx, char *line, t_game *game)
{
	int	direction;

	if (ft_strstartswith(line, "NO"))
		direction = NORTH;
	if (ft_strstartswith(line, "SO"))
		direction = SOUTH;
	if (ft_strstartswith(line, "WE"))
		direction = WEST;
	if (ft_strstartswith(line, "EA"))
		direction = EAST;
	game->texture->wall[direction] = mlx_xpm_to_image(mlx, line + 3, NULL, NULL);
	if (game->texture->wall[direction] == NULL)
		ft_dprintf(STDERR_FILENO, "Cannot load the texture %s\n", line + 3);
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
			parse_attr(line, game);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
