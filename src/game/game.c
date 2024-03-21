/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:59:45 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/21 15:36:15 by lribette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	game->map = NULL;
	game->texture = ft_calloc(1, sizeof(t_textures));
	game->texture->ceiling = -1;
	game->texture->floor = -1;
	game->player = ft_calloc(1, sizeof(t_player));
	game->player->position = ft_calloc(1, sizeof(t_2dvector));
	game->player->position->h = 0;
	game->player->position->v = 0;
	game->player->camera = ft_calloc(1, sizeof(t_2dvector));
	game->player->camera->h = 0;
	game->player->camera->v = 0;
	game->player->fov = (t_2dvector){.h = 0, .v = 0};
	ft_bzero(game->texture->wall, 4 * sizeof(void *));
	ft_bzero(game->texture->door, 4 * sizeof(void *));
	return (game);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->texture->wall[i])
			free(game->texture->wall[i]);
		i++;
	}
	free_table(game->map);
	if (game->texture)
		free(game->texture);
	if (game->player->position)
		free(game->player->position);
	if (game->player->camera)
		free(game->player->camera);
	if (game->player)
		free(game->player);
	if (game)
		free(game);
}
