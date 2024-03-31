/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lribette <lribette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:59:45 by aboyreau          #+#    #+#             */
/*   Updated: 2024/03/31 16:00:33 by aboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "libft.h"
#include "mlx.h"
#include "controls.h"
#include "game.h"
#include "cub3d.h"

void	free_mlx(t_textures *texture)
{
	if (texture->mlx)
	{
		if (texture->game)
			mlx_destroy_image(texture->mlx, texture->game);
		if (texture->map)
			mlx_destroy_image(texture->mlx, texture->map);
		if (texture->window != NULL)
		{
			mlx_clear_window(texture->mlx, texture->window);
			mlx_destroy_window(texture->mlx, texture->window);
		}
		mlx_destroy_display(texture->mlx);
		free(texture->mlx);
	}
}

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	game->map = NULL;
	game->texture = ft_calloc(1, sizeof(t_textures));
	game->texture->game = NULL;
	game->texture->map = NULL;
	game->texture->window = NULL;
	game->texture->mlx = NULL;
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
	return (game);
}

void	mlx_free_textures(t_textures *texture, int free_textures)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (texture->wall[i])
		{
			if (free_textures == 1)
			{
				mlx_destroy_image(texture->mlx,
					((t_text *)texture->wall[i])->texture);
				free(texture->wall[i]);
			}
			else
				free(texture->wall[i]);
		}
		i++;
	}
	free_mlx(texture);
	free(texture);
}

void	free_game(t_game *game, int free_textures)
{
	free_table(game->map);
	if (game->player->position)
		free(game->player->position);
	if (game->player->camera)
		free(game->player->camera);
	if (game->player)
		free(game->player);
	if (game->texture)
		mlx_free_textures(game->texture, free_textures);
	if (game)
		free(game);
}

void	run_game(t_game *game, long *redraw)
{
	init_keybindings(game->texture->mlx, game->texture->window,
		(void *[]){game, NULL, NULL, redraw});
	game->texture->game = mlx_new_image(game->texture->mlx, WIDTH, HEIGHT);
	game->texture->map = mlx_new_image(game->texture->mlx, \
		(game->longest_line + 1) * SCALE_FACTOR, \
		(ft_tablen(game->map)) * SCALE_FACTOR);
	mlx_loop_hook(game->texture->mlx, (void *)render,
		(void *[]){game->texture->mlx,
		game->texture->window,
		(void *)game, redraw});
	mlx_loop(game->texture->mlx);
}
