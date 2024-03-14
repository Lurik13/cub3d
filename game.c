/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:59:45 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/14 11:45:47 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"

t_game	*init_game()
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	game->texture = ft_calloc(1, sizeof(t_textures));
	game->texture->ceiling = -1;
	game->texture->floor = -1;
	ft_bzero(game->texture->wall, 4 * sizeof(void *));
	ft_bzero(game->texture->door, 4 * sizeof(void *));
	return (game);
}

void	free_game(void *mlx, t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(mlx, game->texture->wall[i]);
		mlx_destroy_image(mlx, game->texture->door[i]);
	}
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->texture);
	free(game);
}
